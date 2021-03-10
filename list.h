#ifndef LIST_H
#define LIST_H

struct listElement {
    int data;
    listElement* next; 
};

class list {
public:
    list() : p(0) {}

    int pushBack(int newData); 
    int pushFront(int newData);
    void printInfo();
    int popBack();
    int popFront();
    int insertByIndex(int number, int index);
    int deleteByIndex(int index);
    int getElementByIndex(int index);
    int size();

private:
    listElement* p;
};

#endif // LIST_H