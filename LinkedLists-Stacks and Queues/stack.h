#ifndef __STACK_H
#define __STACK_H
#include "list.cpp"

/* This is the generic Stack class */
template <class T>
class Stack
{
    List<T> list;

public:

    // Constructor
    Stack();

    // Copy Constructor
     Stack(const Stack<T>& otherStack);

    // Destructor
    ~Stack();

    // Required Methods
    void push(T item);
    T top();
    T pop();
    int length();
    bool isEmpty();
};

#endif
