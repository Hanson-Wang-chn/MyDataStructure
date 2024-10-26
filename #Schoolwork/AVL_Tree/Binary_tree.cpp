#include "Binary_tree.h"
#include "MyStack.cpp"
template <class Entry>
Binary_tree<Entry> :: Binary_tree( )
/* Post: An empty binary tree has been created. */
{
	root = NULL;
	count = 0;
}

template <class Entry>
bool Binary_tree<Entry> :: empty( ) const
/* Post: A result oftrue is returned if the binary tree is empty. Otherwise,false is
returned. */
{
	return root == NULL;
}

template <class Entry>
void Binary_tree<Entry> :: preorder(void (*visit)(Entry &))
{
	recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry> :: recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
	if (sub_root != NULL) {
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left, visit);
		recursive_preorder(sub_root->right, visit);
	} 
}

template <class Entry>
void Binary_tree<Entry> :: inorder(void (*visit)(Entry &))
/* Post: The tree has been been traversed in infix order sequence.
Uses: The function recursive_inorder */
{
	recursive_inorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry> :: recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
/* Pre: sub_root is either NULL or points to a subtree of the Binary tree .
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive inorder_recursively */
{
	if (sub_root != NULL) {
		recursive_inorder(sub_root->left, visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right, visit);
	} 
}

template <class Entry>
void Binary_tree<Entry> :: postorder(void (*visit)(Entry &))
{
	recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry> :: recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
	if (sub_root != NULL) {
		recursive_postorder(sub_root->left, visit);
		recursive_postorder(sub_root->right, visit);
		(*visit)(sub_root->data);
	} 
}

template <class Entry>
int Binary_tree<Entry> :: size( ) const
{
	return count;
}

template <class Entry>
int Binary_tree<Entry> :: height( ) const
{
	int count=size();
	if(count==0)return 0;
	int tmp=1;
	for(int i=-1; tmp<=count; i++)tmp*=2;
	return i;
}

template <class Entry>
void Binary_tree<Entry> :: insert(Entry &x)
{
	if(empty()){
		root=new Binary_node<Entry>(x);
		count++;
		return;
	}
	MyStack<int> numbers;
	int item=0;
    int tmpcount=size();
    while(tmpcount>0){
		int a=(tmpcount-1)/2;
 	    int b=(tmpcount-2)/2;
	    if(tmpcount>1 && a==b){//the node is right child
		   numbers.push(2);//2 stand for right child
		} 
	    else{//the node is left child
		   numbers.push(1);//1 stand for left child
		} 
	    tmpcount=(tmpcount-1)/2;//get to the parent
	}
	Binary_node<Entry> *current=root;
	while (numbers.size()>1) {
		numbers.top(item); 
        if(item==1)current=current->left;
		if(item==2)current=current->right;
        numbers.pop();
	} 
	numbers.top(item);
	if(item==1)current->left=new Binary_node<Entry>(x);
	if(item==2)current->right=new Binary_node<Entry>(x);
	count++;
}
