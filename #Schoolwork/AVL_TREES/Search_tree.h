#include "Binary_tree.cpp"
template <class Record>
class Search_tree: public Binary_tree<Record> {
public:
	Error_code insert(const Record &new_data);
	Error_code remove(const Record &target);
	Error_code tree_search(Record &target) const;
private: // Add auxiliary function prototypes here.
	Binary_node<Record> *search_for_node(Binary_node<Record>* sub_root, const Record &target) const;
	Error_code search_and_insert(Binary_node<Record> * &sub_root, const Record &new_data);
	Error_code search_and_destroy(Binary_node<Record>* &sub_root, const Record &target);
	Error_code remove_root(Binary_node<Record> * &sub_root);

};
