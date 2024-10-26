#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
using namespace std;
class Record{
public:
    //operator Key( ); // implicit conversion from Record to Key .
    Record(int x=0, int y=0);
    int the_key() const;
private:
    int key;
    int other;
};

bool operator > (const Record &x, const Record &y);

bool operator >= (const Record &x, const Record &y);

bool operator < (const Record &x, const Record &y);

bool operator <= (const Record &x, const Record &y);

ostream & operator << (ostream &output, Record &x);
#endif // RECORD_H_INCLUDED