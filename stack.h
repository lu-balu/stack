#include "list.h"
#include <cstddef>

class Stack {
public:
    Stack();
    void push(int newData);
    int pop();
    int top();
    size_t size();

private:
    list l;
    size_t _size;
};
