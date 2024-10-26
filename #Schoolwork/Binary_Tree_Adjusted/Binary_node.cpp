#include "Binary_node.h"

template <class Entry>
Binary_node<Entry> :: Binary_node(){
    left = nullptr;
    right = nullptr;
}

template <class Entry>
Binary_node<Entry> :: Binary_node(const Entry &x){
    data = x;
    left = nullptr;
    right = nullptr;
}