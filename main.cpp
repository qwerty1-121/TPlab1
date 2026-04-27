#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFileInfo>

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
    QFileInfo fileInfo(filePath);

    bool exists = fileInfo.exists();
    qint64 size = fileInfo.size();

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