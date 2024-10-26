#include "Binary_node.cpp"

template <class Record>
struct AVL_node: public Binary_node<Record> {
// additional data member:
    Balance_factor balance;
// constructors:
    AVL_node( );
    AVL_node(const Record &x);
// overridden virtual functions:
    void set_balance(Balance_factor b);
    Balance_factor get_balance( ) const;
};
