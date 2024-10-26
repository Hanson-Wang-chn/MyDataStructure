#include"Record.h"
Record::Record(int x,int y)
{
    key=x;
    other=y;
}

int Record::the_key()const
{
return key;
}

int Record::the_other()const
{
return other;
}

Record::operator Key()
{
    Key tmp(key);
    return tmp;
}

bool operator!=(const Record&x,const Record&y)
{
    return x.the_key()!=y.the_key();
}

bool operator==(const Record&x,const Record&y)
{
    return x.the_key()==y.the_key();
}
