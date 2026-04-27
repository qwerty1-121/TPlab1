#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextStream out(stdout);

    out << "Lab_1 File Watcher started" << Qt::endl;
    out << "Qt console application" << Qt::endl;
    out << "Project setup step" << Qt::endl;

    QString filePath = "empty.txt";
    bool exists = true;
    qint64 size = 125;

    out << "filePath: " << filePath << Qt::endl;

    if (exists) {
        out << "File exists" << Qt::endl;
        if (size == 0) {
            out << "File is empty" << Qt::endl;
        }
        else {
            out << "File is not empty" << Qt::endl;
            out << "Size: " << size << " bytes" << Qt::endl;
        }
           
    }
    else {
        out << "File does not exist" << Qt::endl;
    }
    return 0;
}