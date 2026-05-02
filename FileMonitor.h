#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QString>

#include "FileState.h"

class FileMonitor : public QObject
{
    Q_OBJECT

public:
    FileMonitor(QString filePath);

    FileState readState();
    void check();

signals:
    void fileChanged(QString message);

private:
    QString m_filePath;
    FileState m_oldState;
};

#endif // FILEMONITOR_H