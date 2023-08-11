#include "systemresource.h"

SystemResource::SystemResource(QString name, int resourceId, int count)
{
    this->name = name;
    this->count = count;
    this->resourceId = resourceId;
}
