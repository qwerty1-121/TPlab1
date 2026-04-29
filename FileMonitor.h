#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QString>

#include "FileState.h"

class FileMonitor
{
public:
    FileMonitor(QString filePath);

    FileState readState();
    QString check();

private:
    QString m_filePath;
    FileState m_oldState;
};

#endif // FILEMONITOR_H