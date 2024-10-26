#include"LinkList.h"

template<class List_entry>
/*
post：构造函数
*/
List<List_entry>::List()
{
    count=0;
    head=0;
    current_position=0;//int 为现在的位置
    current=0;//指针
}

template<class List_entry>
void List<List_entry>::set_position(int position) const
/*
post：将current指向position的位置
*/
{
    if(current_position<position){//目前的指向position前的位置
        for(;current_position!=position;current_position++){
            current=current->next;//向后移动
        }
    }
    else{//目前的指向position后的位置
        for(;current_position!=position;current_position--){
            current=current->back;//向前移动
        }
    }

}

template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
post：在position的位置插入一个节点
*/
{
    Node<List_entry> *newp,*pre,*post;
    if(position<0||position>count)
        return Range_Error;//越界

    if(position==0){//在开头处加一个节点
        if(count==0) post=0;
        else{
            set_position(0);
            post=current;
        }
        pre=0;

    }
    else{//在list内部插入
        set_position(position-1);
        pre=current;
        post=pre->next;
    }
    newp=new Node<List_entry>(x,pre,post);//新的节点
    if(newp==0) return overflow;//new 失败 overflow
    if(pre!=0) pre->next=newp;
    if(post!=0) post->back=newp;
    current=newp;
    current_position=position;
    if(position==0) head=newp;
    count++;
    return success;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
/*
post：在position的位置移除一个节点
*/
{
    if(position<0||position>count)
        return Range_Error;//越界
    Node<List_entry> *pre,*post;
    if(position>0){//在list内部移除节点
        set_position(position-1);//取得前一个位置的节点
        pre=current;
        post=pre->next;
        pre->next=post->next;//指针移动
        if(post->next) post->next->back=pre;
    }
    else{//在头节点进行删去操作
        post=head;
        head=head->next;
        if(head) head->back=0;
        current_position=0;
        current=head;
    }
    x=post->entry;//用x储存被移除的值
    delete post;//释放空间
    count--;
    return success;
}

template <class List_entry>
Error_code List<List_entry> :: retrieve(int position, List_entry &x) const
/*
post：在position的位置取得一个节点
*/
{
    if (position < 0 || position >= count)
        return Range_Error;//越界
    Node<List_entry> *p_node;
    p_node=set_position(position);
    x=p_node->entry;//将position处的值赋值给x；
    return success;
}

template <class List_entry>
Error_code List<List_entry> ::replace(int position, const List_entry &x)
/*
post：在position的位置替换一个节点
*/
{
    if (position < 0 || position >= count)
        return Range_Error;//越界
    Node<List_entry> *p;//定义一个新的节点
    p=set_position(position);//取位置
    p->entry=x;//将值赋为x
    return success;
}

template <class List_entry>
bool List<List_entry>::empty()const
/*
post：判断列表是否为空
*/
{
    return count==0;
}

template <class List_entry>
int List<List_entry>::size()const
/*
post：返回列表的大小
*/
{
    return count;
}

template <class List_entry>
bool List<List_entry>::full()const
/*
post：判断列表是否已满
*/
{
    Node<List_entry> *newp;
    newp=new Node<List_entry>;//new一个新节点
    if(newp==0)//如果new失败，则已满
        return true;
    else{
        delete newp;
        return false;
    }
}

template <class List_entry>
void List<List_entry>::clear()
/*
post：清空列表
*/
{
    List_entry x;
    while(!empty())//非空时，一直clear
        remove(0,x);
}

template <class List_entry>
List<List_entry> :: List(const List<List_entry> &copy)
/*
post：构造拷贝函数
*/
{
    count = 0;
    head = 0;
    Node<List_entry> *q = copy.head;
    int i=0;

    while(q){//当q不指向null的时候，将元素一个一个往后加
        insert(i,q->entry);
        q=q->next;
        i++;
    }
}

template <class List_entry>
void List<List_entry> :: traverse(void (*visit)(List_entry &))//这里以函数作为参数，在遍历的时候执行函数
/*
post：遍历整个列表
*/
{
    Node<List_entry> *p_node=head;
    while(p_node!=0){
        (*visit)(p_node->entry);//执行visit函数
        p_node=p_node->next;
    }
}

template <class List_entry>
void List<List_entry> :: operator =(const List<List_entry> &copy)
/*
post：操作符重载，重新定义=，使得可以给list之间进行赋值
*/
{
    List_entry x;
    if(this==&copy) return ;//要把相同的情况直接剔除
    while(!empty()) remove(0,x);
    Node<List_entry> *q=copy.head;
    int i=0;
    while(q){//拷贝函数相同的形式
        insert(i,q->entry);
        q=q->next;
        i++;
    }
}

template <class List_entry>
List<List_entry>::~List()
/*
post：析构函数
*/
{
    List_entry x;
    while(!empty())
        remove(0,x);//结束时将list清空
}