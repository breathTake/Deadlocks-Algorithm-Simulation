#ifndef SYSTEMRESOURCE_H
#define SYSTEMRESOURCE_H

#include <QString>

class SystemResource
{


private:

    QString name;
    int resourceId;
    int count;

public:

    SystemResource(QString name, int resourceId, int count);
    SystemResource(QString name, int count);


    int getResourceId() const{
        return resourceId;
    }

    void setResourceId(int resourceId);

    const QString &getName() const {
        return name;
    }

    void setName(const QString &name) {
        SystemResource::name = name;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        this->count = count;
    }

    void decreaseCount(int count){
        this->count -= count;
    }

    void print();

signals:

};

#endif // SYSTEMRESOURCE_H
