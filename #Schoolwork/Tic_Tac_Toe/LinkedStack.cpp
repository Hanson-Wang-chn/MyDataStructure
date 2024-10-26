//
// Created by 王海生 on 2024/5/10.
//

#include"LinkedStack.h"
#include<iostream>
using namespace std;

Node::Node()
/*
post:initialize
*/
{
    next=0;
}

Node::Node(Node_entry item,Node* add_on)
/*
post:����һ���µĽڵ㣻
*/
{
    entry=item;
    next=add_on;
}

Stack::Stack()
{
    top_node=0;//��ʼ��
}

bool Stack::empty()const
{
    return (top_node==0);
}

Error_code Stack::push(const Node_entry &item)
/*
Post: Stack_entry item is added to the top of the Stack; returns success or returns a code
      of overflow if dynamic memory is exhausted.
*/
{
    Node* p=new Node(item,top_node);//����һ���µĽڵ�
    if(p==0) return overflow;//���ڴ�����cpu������ʱnew�½ڵ�ʧ�ܣ�
    top_node=p;
    return success;//����ͨ��stack��һ���ĵط�����push��ʱ���ջ���Ķ���ʽ�������
}

Error_code Stack::pop()
/*
Post: The top of the Stack is removed.
If the Stack is empty the method returns underflow; otherwise it returns success.
*/

{
    Node *tmp=top_node;
    if(top_node==0) return underflow;
    top_node=tmp->next;
    delete tmp;
    return success;
}

Error_code Stack::top(Node_entry&item)const
/*
Post:get the top of the stack.
*/
{
    if(empty()) return underflow;
    item=top_node->entry;
    return success;
}

Stack::~Stack()
/*
Post: The Stack is cleared.
*/

{
    while(!empty())
        pop();
}
