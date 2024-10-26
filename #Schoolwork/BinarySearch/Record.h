#include"Key.h"
#include<iostream>

class Record
{
public:
    operator Key();//从Key到int的隐式转换
    Record(int x = 0, int y = 0);
    int the_key()const;
private:
    int key;
    int other;
};

bool operator>(const Record& x, const Record& y);
bool operator<(const Record& x, const Record& y);

std::ostream & operator<<(std::ostream& output, Record&x);