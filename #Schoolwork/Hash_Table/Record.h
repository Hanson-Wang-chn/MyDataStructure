#include "Key.h"



class Record{

public:

	operator Key( ); // implicit conversion from Record to Key .

	Record(int x=0, int y=0);

	int the_key( ) const;

	int the_other() const;



private:

	int key;

	int other;

};



bool operator != (const Record &x, const Record &y);

bool operator == (const Record &x, const Record &y);







