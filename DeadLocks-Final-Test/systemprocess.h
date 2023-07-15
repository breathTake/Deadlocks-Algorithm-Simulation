#ifndef SYSTEMPROCESS_H
#define SYSTEMPROCESS_H

#include <QObject>
#include "systemressource.h"

using std::vector;

class SystemProcess : public QObject
{
    Q_OBJECT
private:
    QString name;
    int processId;

    QList<SystemRessource> neededRessources;
    QList<SystemRessource> assignedRessources;

public:
    explicit SystemProcess(QObject *parent = nullptr);

    void setName(const QString &name) {
        SystemProcess::name = name;
    }

    const QList<SystemRessource> &getNeededRessources() const {
        return neededRessources;
    }

    void setNeededRessources(const QList<SystemRessource> &neededRessources) {
        SystemProcess::neededRessources = neededRessources;
    }

    const QList<SystemRessource> &getAssignedRessources() const {
        return assignedRessources;
    }

    void setAssignedRessources(const QList<SystemRessource> &assignedRessources) {
        SystemProcess::assignedRessources = assignedRessources;
    }

    SystemProcess(QString name,int processId, int min, int max);
    void requestRessource(SystemRessource ressource, int count);
    void releaseRessource(SystemRessource ressource, int count);
    void print();

signals:

};

#endif // SYSTEMPROCESS_H
