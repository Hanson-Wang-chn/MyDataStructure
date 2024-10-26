#include"Node.h"

template<class Node_entry>
Node<Node_entry>::Node( )
{
    back = 0;
    next = 0;//initialization
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *link_back, Node<Node_entry> *link_next)
{
    entry = item;
    back = link_back;
    next = link_next;//¹¹Ôìº¯Êý
}