#include"Record.h"

#include"List.cpp"
class Ordered_list: public List<Record>{
public:
    Error_code insert(const Record &data);
    Error_code insert(int position, const Record &data);
    Error_code replace(int position, const Record &data);
};