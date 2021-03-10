#include "stack.h"
#include <iostream>
#include <cstddef>

Stack::Stack(): size(0) {}

void Stack::push(int newData) {
    pushFront(newData);
    ++size;

}

int Stack::pop(){
    return popFront();
    --size;
}

int Stack::top(){
    return getElementByIndex(0);
}

size_t Stack::getSize(){
    return size;
}