#include "TimeType.h"

// 构造函数，初始化时间为传入的参数值
TimeType::TimeType(int initHrs, int initMins, int initSecs) {
    hrs = initHrs;
    mins = initMins;
    secs = initSecs;
}

// 默认构造函数，初始化时间为 00:00:00
TimeType::TimeType() {
    hrs = 0;
    mins = 0;
    secs = 0;
}

// 设置时间的函数
void TimeType::Set(int hours, int minutes, int seconds) {
    hrs = hours;
    mins = minutes;
    secs = seconds;
}

// 增加时间的函数，每次调用增加一秒
void TimeType::Increment() {
    secs++;
    if (secs >= 60) {
        secs = 0;
        mins++;
        if (mins >= 60) {
            mins = 0;
            hrs++;
            if (hrs >= 24) {
                hrs = 0;
            }
            // 如果小时刚好是整数小时，则输出整点报时
            cout << hrs << "点整点报时.........." << endl;
        }
    }
}

// 输出当前时间的函数，格式为 HH:MM:SS
void TimeType::Write() const {
    cout << (hrs < 10 ? "0" : "") << hrs << ":"
         << (mins < 10 ? "0" : "") << mins << ":"
         << (secs < 10 ? "0" : "") << secs << endl;
}

// 判断两个时间是否相等的函数
bool TimeType::Equal(TimeType otherTime) const {
    return (hrs == otherTime.hrs &&
            mins == otherTime.mins &&
            secs == otherTime.secs);
}

// 判断当前时间是否小于另一个时间的函数
bool TimeType::LessThan(TimeType otherTime) const {
    if (hrs < otherTime.hrs) return true;
    if (hrs > otherTime.hrs) return false;
    if (mins < otherTime.mins) return true;
    if (mins > otherTime.mins) return false;
    return secs < otherTime.secs;
}
