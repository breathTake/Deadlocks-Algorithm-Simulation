#ifndef DEADLOCK_AVOIDANCE_API_H
#define DEADLOCK_AVOIDANCE_API_H


class deadlock_avoidance_api
{
public:
    deadlock_avoidance_api();

    virtual void avoidance_algorithm() = 0;
};

#endif // DEADLOCK_AVOIDANCE_API_H
