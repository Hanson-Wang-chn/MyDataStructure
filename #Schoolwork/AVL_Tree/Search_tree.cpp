#include "Search_tree.h"

template <class Record>
Binary_node<Record> *Search_tree<Record> :: search_for_node(
Binary_node<Record>* sub_root, const Record &target) const
{
	if (sub_root == NULL || sub_root->data == target)
		return sub_root;
	else if (sub_root->data < target)
		return search_for_node(sub_root->right, target);
	else return search_for_node(sub_root->left, target);
}

/*Nonrecursive version:
template <class Record>
Binary_node<Record> *Search_tree<Record> :: search_for_node(
Binary_node<Record>* sub_root, const Record &target) const
{
	while (sub_root != NULL && sub_root->data != target)
		if (sub_root->data < target) sub_root = sub_root->right;
		else sub_root = sub_root->left;
	return sub_root;
}
*/

template <class Record>
Error_code Search_tree<Record> :: tree_search(Record &target) const
{
	Error_code result = success;
	Binary_node<Record> *found = search_for_node(root, target);
	if (found == NULL)
		result = not_present;
	else
		target = found->data;
	return result;
}

template <class Record>
Error_code Search_tree<Record> :: insert(const Record &new_data)
{
	Error_code result=search_and_insert(root, new_data);
	if(result==success)count++;
	return result;
}

template <class Record>
Error_code Search_tree<Record> :: search_and_insert(
Binary_node<Record> * &sub_root, const Record &new_data)
{
	if (sub_root == NULL) {
		sub_root = new Binary_node<Record>(new_data);
		return success;
	}
	else if (new_data < sub_root->data)
		return search_and_insert(sub_root->left, new_data);
	else if (new_data > sub_root->data)
		return search_and_insert(sub_root->right, new_data);
	else return duplicate_error;
}

template <class Record>
Error_code Search_tree<Record> :: remove(const Record &target)
/* Post: If a Record with a key matching that of target belongs to the Search tree a
code of success is returned and the corresponding node is removed from the
tree. Otherwise, a code of not present is returned.
Uses: Function search_and_destroy */
{
	Error_code result=search_and_destroy(root, target);
	if(result==success)count--;
	return result;
}

template <class Record>
Error_code Search_tree<Record> :: search_and_destroy(
Binary_node<Record>* &sub_root, const Record &target)
/* Pre: sub root is either NULL or points to a subtree of the Search tree .
Post: If the key of target is not in the subtree, a code of not_present is returned.
Otherwise, a code of success is returned and the subtree node containing
target has been removed in such a way that the properties of a binary search
tree have been preserved.
Uses: Functions search and destroy recursively and remove root */
{
	if (sub_root == NULL || sub_root->data == target)
		return remove_root(sub_root);
	else if (target < sub_root->data)
		return search_and_destroy(sub_root->left, target);
	else
		return search_and_destroy(sub_root->right, target);
}

template <class Record>
Error_code Search_tree<Record> :: remove_root(Binary_node<Record> * &sub_root)
/* Pre: sub root is either NULL or points to a subtree of the Search tree .
Post: If sub root is NULL , a code of not_present is returned. Otherwise, the root of
the subtree is removed in such a way that the properties of a binary search tree
are preserved. The parameter sub root is reset as the root of the modified
subtree, and success is returned. */
{
	if (sub_root == NULL) return not_present;
	Binary_node<Record> *to_delete = sub_root;
	// Remember node to delete at end.
	if (sub_root->right == NULL) sub_root = sub_root->left;
	else if (sub_root->left == NULL) sub_root = sub_root->right;
	else { // Neither subtree is empty.
		to_delete = sub_root->left; // Move left to find predecessor.	
		Binary_node<Record> *parent = sub_root; // parent of to_delete
		while (to_delete->right != NULL) { // to_delete is not the predecessor.
			parent = to_delete;
			to_delete = to_delete->right;
		} 
		sub_root->data = to_delete->data; // Move from to_delete to root.
		if (parent == sub_root) sub_root->left = to_delete->left;
		else parent->right = to_delete->left;	
	} 
	delete to_delete; // Remove to_delete from tree.
	return success;
}