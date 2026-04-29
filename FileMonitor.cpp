#include "FileMonitor.h"

FileMonitor::FileMonitor(QString filePath)
{
    m_filePath = filePath;
}

FileState FileMonitor::readState()
{
    FileState state;

    state.path = m_filePath;
    state.update();

    return state;
}