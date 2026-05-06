#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QThread>

#include "FileState.h"
#include "FileMonitor.h"
#include "ConsoleNotifier.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);

    out << "Lab_1 File Watcher started" << Qt::endl;
    out << "Qt console application" << Qt::endl;
    out << "Project setup step" << Qt::endl;

    FileMonitor monitor;
    ConsoleNotifier notifier;

    QObject::connect(
        &monitor,
        &FileMonitor::fileChanged,
        &notifier,
        &ConsoleNotifier::printMessage
    );

    int fileCount = 0;

    out << "Enter file paths." << Qt::endl;
    out << "Enter empty line to start watching." << Qt::endl;

    while (true)
    {
        out << "Enter file path: " << Qt::endl;

        QString filePath = in.readLine();

        if (filePath.isEmpty())
        {
            break;
        }

        monitor.addFile(filePath);
        ++fileCount;

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

    if (fileCount == 0)
    {
        out << "No files to watch." << Qt::endl;
        return 0;
    }

    out << "Watching files. Press Ctrl+C to stop." << Qt::endl;

    while (true)
    {
        QThread::msleep(100);

        monitor.check();
    }

    return 0;
}