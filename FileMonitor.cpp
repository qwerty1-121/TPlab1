#include "FileMonitor.h"

FileMonitor::FileMonitor()
{
}

void FileMonitor::addFile(QString filePath)
{
    // Добавляем начальное состояние файла в список наблюдения
    FileState state = readState(filePath);
    m_oldStates.append(state);
}

FileState FileMonitor::readState(QString filePath)
{
    // Формируем текущее состояние файла
    FileState state;

    state.path = filePath;
    state.update();

    return state;
}

void FileMonitor::check()
{
    // Сравниваем сохранённое состояние каждого файла с текущим
    for (int i = 0; i < m_oldStates.size(); ++i)
    {
        FileState oldState = m_oldStates[i];
        FileState newState = readState(oldState.path);

        QString message;

        if (oldState.exists == false && newState.exists == true)
        {
            message = "File appeared: " + newState.path;
        }
        else if (oldState.exists == true && newState.exists == false)
        {
            message = "File disappeared: " + oldState.path;
        }
        else if (oldState.exists == true && newState.exists == true && oldState.size != newState.size)
        {
            message = "File size changed: "
                    + newState.path
                    + ". Old size: "
                    + QString::number(oldState.size)
                    + " bytes. New size: "
                    + QString::number(newState.size)
                    + " bytes.";
        }

        // Сохраняем новое состояние для следующей проверки
        m_oldStates[i] = newState;

        // Если изменение найдено, отправляем сигнал
        if (!message.isEmpty())
        {
            emit fileChanged(message);
        }
    }
}