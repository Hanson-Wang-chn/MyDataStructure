#include "Sortable_list.h"
#include <iostream>
using namespace std;

template <class List_entry>
void print(List_entry &x){
    cout<<x;
}

int main(){
    Sortable_list mylist;
    for(int i=0; i<10; i++)
        mylist.insert(i,Record(10-i,10));
    cout<<"The list is: "<<endl;
    mylist.traverse(print);

    cout<<endl<<"Use heap_sort Method:"<<endl;
    mylist.heap_sort();
    mylist.traverse(print);

    cout<<endl<<"Use quick_sort Method:"<<endl;
    mylist.quick_sort();
    mylist.traverse(print);

    cout<<endl<<"Use Mergesort Method:"<<endl;
    Merge_sort(mylist);
    mylist.traverse(print);

    cout<<endl<<"Use insertion_sort Method:"<<endl;
    mylist.insertion_sort();
    mylist.traverse(print);

    cout<<endl<<"Use selection_sort Method:"<<endl;
    mylist.selection_sort();
    mylist.traverse(print);

    cout<<endl<<"Use shell_sort Method:"<<endl;
    mylist.shell_sort();
    mylist.traverse(print);

    cin.get();
    return 0;
}