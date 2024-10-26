//
// Created by 王海生 on 2024/7/8.
//

#ifndef CBROWSER_H
#define CBROWSER_H

#include "Node.h"

template <class Node_entry>
class CBrowser {
private:
    // data members
    Node<Node_entry> * current; //当前游标指针
public:
    // constructors
    bool CanForward();//可以继续往前
    bool Forward();//前进一个节点
    bool CanBack();//可以继续后退
    bool Back();//后退一个节点
    void NewSite(Node_entry site);//将新的site插入到current当前位置的后面
    Node<Node_entry> * GetCurrent();//获得当前游标指针current
    CBrowser();//缺省构造，空链表
    ~CBrowser();//析构，释放所有节点内存
};

#endif //CBROWSER_H
