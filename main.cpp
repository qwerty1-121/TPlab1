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
    QFileInfo oldFileInfo(filePath);

    bool oldExists = oldFileInfo.exists();
    qint64 oldSize = oldFileInfo.size();

    out << "filePath: " << filePath << Qt::endl;
    out << "Old state:" << Qt::endl;

    if (oldExists) {
        out << "File exists" << Qt::endl;
        if (oldSize == 0) {
            out << "File is empty" << Qt::endl;
        }
        else {
            out << "File is not empty" << Qt::endl;
            out << "Size: " << oldSize << " bytes" << Qt::endl;
        }
           
    }
    else {
        out << "File does not exist" << Qt::endl;
    }

    out << "Change the file and press Enter..." << Qt::endl;
    in.readLine();
    QFileInfo newFileInfo(filePath);

    bool newExists = newFileInfo.exists();
    qint64 newSize = newFileInfo.size();

    out << "New state:" << Qt::endl;

    if (newExists) {
        out << "File exists" << Qt::endl;

        if (newSize == 0) {
            out << "File is empty" << Qt::endl;
        }
        else {
            out << "File is not empty" << Qt::endl;
            out << "Size: " << newSize << " bytes" << Qt::endl;
        }
    }
    else {
        out << "File does not exist" << Qt::endl;
    }

    out << "Event:" << Qt::endl;

    if (oldExists == false && newExists == true) {
        out << "File appeared" << Qt::endl;
    }
    else if (oldExists == true && newExists == false) {
        out << "File disappeared" << Qt::endl;
    }
    else if (oldExists == true && newExists == true && oldSize != newSize) {
        out << "File size changed" << Qt::endl;
        out << "Old size: " << oldSize << " bytes" << Qt::endl;
        out << "New size: " << newSize << " bytes" << Qt::endl;
    }
    else {
        out << "No changes" << Qt::endl;
    }
    return 0;
}
    