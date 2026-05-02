#ifndef CONSOLENOTIFIER_H
#define CONSOLENOTIFIER_H

#include <QObject>
#include <QString>

class ConsoleNotifier : public QObject
{
    Q_OBJECT

public:
    ConsoleNotifier();

public slots:
    void printMessage(QString message);
};

#endif // CONSOLENOTIFIER_H