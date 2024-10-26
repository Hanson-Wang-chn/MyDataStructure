#ifndef RECORD_H
#define RECORD_H

// #include "Key.h"
// #include <ostream>

#include "Key.h"
#include <iostream>

class Record {
public:
    Record(int x = 0, int y = 0);
    int the_key() const;
    operator Key(); // 隐式转换 Record 到 Key

private:
    int key;
    int other;
};

bool operator>(const Record& x, const Record& y);
bool operator<(const Record& x, const Record& y);
std::ostream& operator<<(std::ostream& output, Record& x);

#endif // RECORD_H
