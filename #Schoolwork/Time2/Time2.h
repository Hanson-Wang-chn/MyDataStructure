//
// Created by 王海生 on 2024/7/5.
//

#ifndef TIME2_H
#define TIME2_H

#include "TimeType.h"

using namespace std;

class Time2 : public TimeType {
public:
    void Increment(); // 重写 Increment 函数
    Time2(int initHrs, int initMins, int initSecs);
    Time2();

private:
    void CheckCoincidence(); // 检查时针和分针重合的函数
    int coincidenceCount; // 记录重合次数
};

#endif //TIME2_H
