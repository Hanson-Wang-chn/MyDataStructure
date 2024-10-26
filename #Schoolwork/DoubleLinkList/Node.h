#include <iostream>

using namespace std;

//Doubly Linked list
template <class Node_entry>

struct Node {
// data members
    Node_entry entry;
    Node<Node_entry> *next; // 指向后一个节点
    Node<Node_entry> *back; // 指向前一个节点
// constructors
    Node( );
    Node(Node_entry item , Node<Node_entry> *link_back = 0 , Node<Node_entry> *link_next=0);

};