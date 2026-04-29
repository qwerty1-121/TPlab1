#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QString>

#include "FileState.h"

class FileMonitor
{
public:
    FileMonitor(QString filePath);

    FileState readState();

private:
    QString m_filePath;
};

#endif // FILEMONITOR_H