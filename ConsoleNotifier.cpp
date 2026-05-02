#include "ConsoleNotifier.h"

#include <QTextStream>

ConsoleNotifier::ConsoleNotifier()
{
}

void ConsoleNotifier::printMessage(QString message)
{
    QTextStream out(stdout);
    out << message << Qt::endl;
}