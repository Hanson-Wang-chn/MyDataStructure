AVL_node<Record> :: AVL_node(){
    left = NULL;
    right = NULL;
    balance = equal_height;
}

template <class Record>
AVL_node<Record> :: AVL_node(const Record &x){
    data = x;
    left = NULL;
    right = NULL;
    balance = equal_height;
}

template <class Record>
void AVL_node<Record> :: set_balance(Balance_factor b)
{
    balance = b;
}

template <class Record>
Balance_factor AVL_node<Record> :: get_balance( ) const
{
    return balance;
}