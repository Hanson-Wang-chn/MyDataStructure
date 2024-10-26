#include <iostream>
#include"LinkList.cpp"

using namespace std;

template <class List_entry>
void update(List_entry &x){
    x*=2;
}//用于traverse函数，将list的元素翻倍

template <class List_entry>
void print(List_entry &x){
    cout<<x<<endl;
}//用于traverse函数，输出整个list


int main()
{
    List<int> mylist;
    for(int i=0;i<5;i++)mylist.insert(i,i);
    int i;
    cout<<"Your list have "<<mylist.size()<<" elements:"<<endl;
    mylist.traverse(print);
    mylist.remove(1, i);
    cout<<"After remove(1):"<<endl;
    mylist.traverse(print);
    mylist.remove(0, i);
    cout<<"After remove(0):"<<endl;
    mylist.traverse(print);

    List<int> mylist2(mylist);
    cout<<"After mylist2(mylist):"<<endl;
    mylist2.traverse(print);

    cout<<"After update:"<<endl;
    mylist.traverse(update);
    mylist.traverse(print);

    List<int> mylist3;
    mylist3=mylist;
    cout<<"After mylist3=mylist:"<<endl;
    mylist3.traverse(print);

    return 0;
}