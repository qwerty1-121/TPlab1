#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QThread>

#include "FileMonitor.h"

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

    FileState oldState = monitor.readState();

    out << "filePath: " << filePath << Qt::endl;
    out << "Old state:" << Qt::endl;

    if (oldState.exists) {
        out << "File exists" << Qt::endl;
        if (oldState.size == 0) {
            out << "File is empty" << Qt::endl;
        }
        else {
            out << "File is not empty" << Qt::endl;
            out << "Size: " << oldState.size << " bytes" << Qt::endl;
        }
           
    }
    else {
        out << "File does not exist" << Qt::endl;
    }

    out << "Watching file. Press Ctrl+C to stop." << Qt::endl;

    while (true){
        QThread::msleep(100);

        FileState newState = monitor.readState();

        if (oldState.exists == false && newState.exists == true){
            out << "File appeared" << Qt::endl;
        }

        else if (oldState.exists == true && newState.exists == false){
            out << "File disappeared" << Qt::endl;
        }
        else if (oldState.exists == true && newState.exists == true && oldState.size != newState.size){
            out << "File size changed" << Qt::endl;
            out << "Old size: " << oldState.size << " bytes" << Qt::endl;
            out << "New size: " << newState.size << " bytes" << Qt::endl;
        }
        oldState = newState;
    }
    return 0;
}
    