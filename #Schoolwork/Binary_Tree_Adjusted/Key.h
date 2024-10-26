#ifndef KEY_H
#define KEY_H

class Key {
public:
    Key(int x = 0);
    int the_key() const;

private:
    int key;
};

bool operator==(const Key& x, const Key& y);

#endif // KEY_H
