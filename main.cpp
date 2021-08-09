#include <iostream>
#include "stack.h"

int main(){
    Stack stack;
    for(int i = 0; i <10; i++){
        stack.push(i + 1);
    }
    for(int i = 0; i < 5; i++){
        std::cout << "Размер: " << stack.size() << "." << std::endl;
        std::cout << "Удаляется последний элемент " << stack.pop() << "." << std::endl;
        std::cout << "Теперь последний элемент " << stack.top() << std::endl;
    }
    std::cout << std::endl;
};
