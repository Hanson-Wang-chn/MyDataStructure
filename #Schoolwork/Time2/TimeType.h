//
// Created by 王海生 on 2024/7/5.
//

#ifndef TIMETYPE_H
#define TIMETYPE_H

#include <iostream>

using namespace std;

class TimeType {
public:
    void Set(int hours, int minutes, int seconds);
    void Increment();
    void Write() const;
    bool Equal(TimeType otherTime) const;
    bool LessThan(TimeType otherTime) const;
    TimeType(int initHrs, int initMins, int initSecs);
    TimeType();

protected:
    int hrs;
    int mins;
    int secs;
};

#endif //TIMETYPE_H
