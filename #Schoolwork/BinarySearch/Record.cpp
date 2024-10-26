#include"Record.h"

Record::Record(int x, int y)
{
    key = x;
    other = y;
}

Record::operator Key()
{
    Key tmp(key);
    return tmp;
}

int Record::the_key()const
{
    return key;
}

bool operator>(const Record& x, const Record& y)
{
    return x.the_key() > y.the_key();
}

bool operator<(const Record& x, const Record& y)
{
    return x.the_key() < y.the_key();
}

std::ostream& operator<<(std::ostream& output, Record& x)
{
    output << x.the_key();
    output << "  ";
    return output;
}