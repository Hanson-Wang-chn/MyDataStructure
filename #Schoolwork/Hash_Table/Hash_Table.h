#include"Record.h"
enum Error_code{not_present,overflow,duplicate_error,success};
const int hash_size=97;
class Hash_table
{
public:
    void clear();
    Error_code insert(const Record&new_entry);
    Error_code retrieve(const Key&target,Record &found)const;
    Error_code remove(const Key&target,Record&found);
private:
    Record table[hash_size];
};

int hash(const Record &new_entry);

int hash(const Key &new_entry);
