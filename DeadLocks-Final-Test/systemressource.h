#ifndef SYSTEMRESSOURCE_H
#define SYSTEMRESSOURCE_H

#include <QObject>

class SystemRessource : public QObject
{
    Q_OBJECT
public:
    explicit SystemRessource(QObject *parent = nullptr);

private:

    QString name;
    int ressourceId;
    int count;

public:

    SystemRessource(QString name, int ressourceId, int count);

    int getRessourceId() const;

    void setRessourceId(int ressourceId);

    const QString &getName() const {
        return name;
    }

    void setName(const QString &name) {
        SystemRessource::name = name;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        SystemRessource::count = count;
    }


    void print();

signals:

};

#endif // SYSTEMRESSOURCE_H
