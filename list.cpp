#include "list.h"
#include <iostream>
using namespace std;



int list::pushBack(int newData) {
    // Для первой итерации создаем 1 элемент списка
    if(p == 0) {
        // указатель равен 0
        // выделяется память под два элемента (listElement)
        // адрес памяти записывается в p
        p = new listElement; 
        // в поле данные заносятся передаваемые данные
        (*p).data = newData;
        // в поле указателя записывается 0
        (*p).next = 0;
    }       
    else {
        // первый элемент уже существует
        // создается новый указатель
        listElement* currElement;
        // в этот указатель записывается указатель p
        currElement = p;
        // пока что в поле указателя элемента не указано 0 
        while((*currElement).next!= 0) {
            // перезаписываем в указатель - указатель на следующий элемент
            currElement = (*currElement).next;
        }
        // создаетс новый ууказатель
        listElement* newElement;
        // выделяется место под два элемента listElement
        // адрес записывается в указатель
        newElement = new listElement;
        // в поле данных записываются передаваемые данные
        (*newElement).data = newData;
        // в поле указатель записывается 0
        (*newElement).next = 0;
        // в поле указателья предыдущего элемента записывается указатель на последний элемент
        (*currElement).next = newElement; 
    }
}

int list::pushFront(int newData) {
    listElement* newElement;
    newElement = new listElement;
    (*newElement).data = newData;
    (*newElement).next = p;
    p = newElement;
}

void list::printInfo() {
    // создаю указатель и записываю в него указатель p
    listElement* currElement = p;
    while(currElement != 0){
        cout << (*currElement).data << " ";
        currElement = (*currElement).next;
    }   
    cout << endl;
}

int list::popBack() {
    if(p == 0) {
        return -1;
    }
    else {
        listElement* currElement = p;
        listElement* newElement = (*currElement).next;
        while ((*newElement).next != 0) {
            currElement = newElement;
            newElement = (*currElement).next;
        }
        (*currElement).next = 0;
        int result = (*newElement).data;
        delete newElement;
        return result;
    }
}

int list::popFront() {
    listElement* currElement = p;
    p = (*currElement).next;
    int result = (*currElement).data;
    delete currElement;
    return result;
}

int list::insertByIndex(int number, int index) {
    listElement* currElement = p;
    int num = 1;
    if(index == 0) {
        listElement* newElement;
        newElement = new listElement;
        (*newElement).data = number;
        (*newElement).next = p;
        p = newElement;
    }
    else{
        while(num != index) {
            currElement = (*currElement).next;
            ++ num;
            }
        listElement* newElement;
        newElement = new listElement;
        (*newElement).data = number;
        (*newElement).next = (*currElement).next;
        (*currElement).next = newElement;
        }
}

int list::deleteByIndex (int index) {
    if(p == 0) {
        return - 1;
    }
    listElement* currElement = p; 
    if(index == 0){
        p = (*currElement).next;
        int data = (*currElement).data;
        delete currElement;
        return data;
    }
    for(int i = 0; i < index - 1; ++i) {
        currElement = (*currElement).next;
    }
    listElement* deleteElement = (*currElement).next;
    (*currElement).next = (*deleteElement).next;
    int data = (*deleteElement).data;
    delete deleteElement;
    return data;
}

int list::size () {
    int size = 1;
    listElement* currElement = p;
    if(p == 0){
        return -1;
    }
    while((*currElement).next != 0){
        size ++;
        currElement = (*currElement).next;
    }
    return size;
}

int list::getElementByIndex(int index){
    if(p == 0){
        return -1;
    }
    int size = 0;
    listElement* currElement = p;
    while(size != index){
        size++;
        currElement = (*currElement).next;
    }
    return (*currElement).data;
}