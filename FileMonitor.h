#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QString>
#include <QVector>

#include "FileState.h"

class FileMonitor : public QObject
{
    Q_OBJECT

public:
    FileMonitor();

    void addFile(QString filePath);
    FileState readState(QString filePath);

public slots:
    void check();

signals:
    void fileChanged(QString message);

private:
    QVector<FileState> m_oldStates;
};

#endif