#ifndef FILESTATE_H
#define FILESTATE_H

#include <QString>
#include <QtGlobal>

class FileState
{
public:
    void update();

    QString path;
    bool exists;
    qint64 size;
};

#endif // FILESTATE_H