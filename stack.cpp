#include "stack.h"
#include <iostream>

Stack::Stack(): _size(0) {}

void Stack::push(int newData) {
    l.pushFront(newData);
    _size++;
}

int Stack::pop(){
    _size--;
    return l.popFront();
}

int Stack::top(){
    return l.getElementByIndex(0);
}

size_t Stack::size(){
    return _size;
}
