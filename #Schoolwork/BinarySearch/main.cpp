#include "Ordered_list.h"
#include<iostream>
using namespace std;


Error_code recursive_binary_1(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position)

/* Pre: bottom and top define the range in the list to search for the target.

Post: If a Record in the range of locations from bottom totop inthe list has

key equal to target , then position locates one such entry and a code

of success is returned. Otherwise, the Error code of not present is

returned and position becomes undefined.

Uses: recursive_binary_1 and methods of the classes List and Record . */

{

    Record data;

    if (bottom < top) { // List has more than one entry.

        int mid = (bottom + top)/2;

        the_list.retrieve(mid, data);

        if (target > data) // Reduce to top half of list.

            return recursive_binary_1(the_list, target, mid + 1, top, position);

        else // Reduce to bottom half of list.

            return recursive_binary_1(the_list, target,	bottom, mid, position);

    }

    else if (top < bottom)  // Can be remarked.

        return not_present; // List is empty.

    else { // List has exactly one entry.

        position = bottom;

        the_list.retrieve(bottom, data);

        if (data == target) return success;

        else return not_present;

    }

}



Error_code binary_search_1 (const Ordered_list &the_list, const Key &target, int &position)

/* Post: If a Record in the list has Key equal to target , then position locates

one such entry and a code of success is returned.

Otherwise, not_present is returned and position is undefined.

Uses: Methods for classes List and Record . */

{

    Record data;

    int bottom = 0, top = the_list.size( ) - 1;

    while (bottom < top)
    {
        int mid = (bottom + top)/2;

        the_list.retrieve(mid, data);

        if (data < target)

            bottom = mid + 1;

        else

            top = mid;

    }

    if (top < bottom) return not_present;

    else {

        position = bottom;

        the_list.retrieve(bottom, data);

        if (data == target) return success;

        else return not_present;

    }

}



Error_code recursive_binary_2(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position)

/* Pre: The indices bottom to top define the range in the list to search for the

target .

Post: If a Record in the range from bottom to top in the list has key equal

to target , then position locates one such entry, and a code of success

is returned. Otherwise, not_present is returned, and position is undefined.

Uses: recursive_binary_2 , together with methods from the classes

Ordered_list and Record . */

{

    Record data;

    if (bottom <= top) {

        int mid = (bottom + top)/2;

        the_list.retrieve(mid, data);

        if (data == target) {

            position = mid;

            return success;

        }

        else if (data < target)

            return recursive_binary_2(the_list, target, mid + 1, top, position);

        else

            return recursive_binary_2(the_list, target, bottom, mid - 1, position);

    }

    else return not_present;

}



Error_code binary_search_2(const Ordered_list &the_list, const Key &target, int &position)

/* Post: If a Record in the list has key equal to target , then position locates

one such entry and a code of success is returned. Otherwise, not present is returned

and position is undefined.

Uses: Methods for classes Ordered_list and Record . */

{

    Record data;

    int bottom = 0, top = the_list.size( ) - 1;

    while (bottom <= top) {

        position = (bottom + top)/2;

        the_list.retrieve(position, data);

        if (data == target) return success;

        if (data < target) bottom = position + 1;

        else top = position - 1;

    }

    return not_present;

}



template <class List_entry>

void print(List_entry &x){

    cout<<x;

}





int main(){

    Key target(5);

    Ordered_list mylist;

    for(int i=0; i<10; i++) mylist.insert(Record(i,10));

    cout<<"The ordered list is: "<<endl;

    mylist.traverse(print);

    cout<<endl<<"The target is: "<<target.the_key()<<endl;

    int bottom=0;

    int top=mylist.size()-1;

    int position=-1;



    cout<<endl<<"Use recursive_binary_1 Method:"<<endl;

    if(recursive_binary_1(mylist, target, bottom, top, position)==success)

        cout<<"Get the target in position: " << position <<endl;

    else

        cout<<"Target not present."<<endl;



    position=-1;

    cout<<endl<<"Use binary_search_1 Method:"<<endl;

    if(binary_search_1(mylist, target, position)==success)

        cout<<"Get the target in position: " << position <<endl;

    else

        cout<<"Target not present."<<endl;



    position=-1;

    cout<<endl<<"Use recursive_binary_2 Method:"<<endl;

    if(recursive_binary_2(mylist, target, bottom, top, position)==success)

        cout<<"Get the target in position: " << position <<endl;

    else

        cout<<"Target not present."<<endl;



    position=-1;

    cout<<endl<<"Use binary_search_2 Method:"<<endl;

    if(binary_search_2(mylist, target, position)==success)

        cout<<"Get the target in position: " << position <<endl;

    else

        cout<<"Target not present."<<endl;



    cin.get();

    return 0;
}
