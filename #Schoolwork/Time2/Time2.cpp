#include "Time2.h"

// 构造函数，初始化时间并设置重合次数为0
Time2::Time2(int initHrs, int initMins, int initSecs) : TimeType(initHrs, initMins, initSecs) {
    coincidenceCount = 0;
}

// 默认构造函数，初始化时间为00:00:00并设置重合次数为0
Time2::Time2() : TimeType() {
    coincidenceCount = 0;
}

// 重写 Increment 函数，增加时间并检查重合和整点报时
void Time2::Increment() {
    TimeType::Increment();
    CheckCoincidence();
}

// 检查时针和分针重合的函数
void Time2::CheckCoincidence() {
    // 计算时针和分针的位置
    int minuteHandPosition = mins; // 分针在每小时内的位置
    int hourHandPosition = 5 * (hrs % 12) + mins / 12; // 时针在每小时内的位置

    // 如果位置相同，则表示重合
    if (minuteHandPosition == hourHandPosition && secs == mins) {
        coincidenceCount++;
        cout << "第" << coincidenceCount << "次重合，重合时间："
             << (hrs < 10 ? "0" : "") << hrs << ":"
             << (mins < 10 ? "0" : "") << mins << ":"
             << (secs < 10 ? "0" : "") << secs << endl;
    }
}
