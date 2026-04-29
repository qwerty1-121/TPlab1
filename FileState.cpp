#include "FileState.h"

#include <QFileInfo>

void FileState::update()
{
    QFileInfo fileInfo(path);

    exists = fileInfo.exists();
    size = fileInfo.size();
}