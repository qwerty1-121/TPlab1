#include "FileMonitor.h"

FileMonitor::FileMonitor(QString filePath)
{
    m_filePath = filePath;
    m_oldState = readState();
}

FileState FileMonitor::readState()
{
    FileState state;

    state.path = m_filePath;
    state.update();

    return state;
}

QString FileMonitor::check()
{
    FileState newState = readState();

    QString message;

    if (m_oldState.exists == false && newState.exists == true)
    {
        message = "File appeared";
    }
    else if (m_oldState.exists == true && newState.exists == false)
    {
        message = "File disappeared";
    }
    else if (m_oldState.exists == true && newState.exists == true && m_oldState.size != newState.size)
    {
        message = "File size changed. Old size: "
                + QString::number(m_oldState.size)
                + " bytes. New size: "
                + QString::number(newState.size)
                + " bytes.";
    }

    m_oldState = newState;

    return message;
}