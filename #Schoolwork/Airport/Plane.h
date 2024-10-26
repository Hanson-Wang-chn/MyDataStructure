//
// Created by 王海生 on 2024/3/13.
//

#ifndef AIRPORT_PLANE_H
#define AIRPORT_PLANE_H

#include "utility.h"

class Plane {
public:
    Plane();
    Plane(int flt, int time, Plane_status status);
    void refuse() const;
    void land(int time) const;
    void fly(int time) const;
    int started() const;

private:
    int flt_num;
    int clock_start;
    Plane_status state;
};

#endif //AIRPORT_PLANE_H
