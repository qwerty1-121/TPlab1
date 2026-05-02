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

    out << "Enter file path: " << Qt::endl;

    QString filePath = in.readLine();

    FileMonitor monitor(filePath);
    ConsoleNotifier notifier;

    QObject::connect(
        &monitor,
        &FileMonitor::fileChanged,
        &notifier,
        &ConsoleNotifier::printMessage
    );

    FileState currentState = monitor.readState();

    out << "filePath: " << filePath << Qt::endl;
    out << "Old state:" << Qt::endl;

    if (currentState.exists) {
        out << "File exists" << Qt::endl;

        if (currentState.size == 0) {
            out << "File is empty" << Qt::endl;
        }
        else {
            out << "File is not empty" << Qt::endl;
            out << "Size: " << currentState.size << " bytes" << Qt::endl;
        }
    }
    else {
        out << "File does not exist" << Qt::endl;
    }

    out << "Watching file. Press Ctrl+C to stop." << Qt::endl;

    while (true)
    {
        QThread::msleep(100);

        monitor.check();
    }

    return 0;
}