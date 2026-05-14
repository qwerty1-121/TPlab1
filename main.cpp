#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QThread>

#include "FileState.h"
#include "FileMonitor.h"
#include "ConsoleNotifier.h"

int main(int argc, char *argv[])
{
    // Инициализация консольного Qt-приложения
    QCoreApplication app(argc, argv);

    // Потоки для ввода и вывода в консоль
    QTextStream in(stdin);
    QTextStream out(stdout);

    out << "Lab_1 File Watcher started" << Qt::endl;
    out << "Qt console application" << Qt::endl;
    out << "Project setup step" << Qt::endl;

    // monitor следит за файлами, notifier выводит сообщения
    FileMonitor monitor;
    ConsoleNotifier notifier;

    // Связываем сигнал изменения файла со слотом вывода сообщения
    QObject::connect(
        &monitor,
        &FileMonitor::fileChanged,
        &notifier,
        &ConsoleNotifier::printMessage
    );

    int fileCount = 0;

    out << "Enter file paths." << Qt::endl;
    out << "Enter empty line to start watching." << Qt::endl;

    // Ввод путей к файлам до пустой строки
    while (true)
    {
        out << "Enter file path: " << Qt::endl;

        QString filePath = in.readLine();

        // Пустая строка завершает ввод файлов
        if (filePath.isEmpty())
        {
            break;
        }

        // Добавляем файл в наблюдение
        monitor.addFile(filePath);
        ++fileCount;

        // Считываем и выводим начальное состояние файла
        FileState currentState = monitor.readState(filePath);

        out << "filePath: " << filePath << Qt::endl;
        out << "Initial state:" << Qt::endl;

        if (currentState.exists)
        {
            out << "File exists" << Qt::endl;

            if (currentState.size == 0)
            {
                out << "File is empty" << Qt::endl;
            }
            else
            {
                out << "File is not empty" << Qt::endl;
                out << "Size: " << currentState.size << " bytes" << Qt::endl;
            }
        }
        else
        {
            out << "File does not exist" << Qt::endl;
        }
    }

    // Если пользователь не ввёл ни одного файла, завершаем программу
    if (fileCount == 0)
    {
        out << "No files to watch." << Qt::endl;
        return 0;
    }

    out << "Watching files. Press Ctrl+C to stop." << Qt::endl;

    // Бесконечный цикл проверки файлов
    while (true)
    {
        // Пауза между проверками — 100 мс
        QThread::msleep(100);

        // Проверка изменений файлов
        monitor.check();
    }

    return 0;
}