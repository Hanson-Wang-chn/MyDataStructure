//
// Created by 王海生 on 2024/5/10.
//

#ifndef TIC_TAC_TOE_LINKEDSTACK_H
#define TIC_TAC_TOE_LINKEDSTACK_H

#include"Move.h"
enum Error_code{underflow,overflow,success};
typedef Move Node_entry;

struct Node{
    Node_entry entry;//data
    Node *next;//pointer
    Node();
    Node(Node_entry item,Node*add_on);
};

class Stack
{
public:
    Stack();
    bool empty() const;
    Error_code push(const Node_entry &item);
    Error_code pop();
    Error_code top(Node_entry &item)const;
    ~Stack();//��ͬ������ʱ�������ڳ������ʱ�ͷ��ڴ档������������
protected:
    Node*top_node;
};


#endif //TIC_TAC_TOE_LINKEDSTACK_H