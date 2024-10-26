#include "Hash_Table.h"

#include <iostream>
using namespace std;

int main()
{
	Hash_table myhash;
	myhash.insert(Record(3,20));
	myhash.insert(Record(5,30));
	myhash.insert(Record(9,50));

	Record target;
	myhash.retrieve(Key(5),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;

	target=Record(0,0);
	myhash.retrieve(Key(3),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;

	target=Record(0,0);
	myhash.remove(Key(3),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;

	target=Record(0,0);
	myhash.retrieve(Key(3),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;
	cin.get();
    return 0;
}




