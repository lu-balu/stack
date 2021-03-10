#include "list.h"
#include <cstddef>

class Stack : private list{
    public:
        Stack();
        void push(int newData);
        int pop();
        int top();
        size_t getSize();

    private:
        size_t size;
};