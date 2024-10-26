class Key
{
    int key;
public:
    Key(int x = 0);
    int the_key()const;//返回Key对象中的键值
};

//重载==运算符，比较两个Key对象是否相等
bool operator==(const Key& x, const Key& y);
//重载>和<运算符，比较两个Key对象的大小
bool operator<(const Key& x, const Key& y);
bool operator>(const Key& x, const Key& y);