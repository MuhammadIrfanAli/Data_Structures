#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack()
{
}


template <class T>
Stack<T>::Stack(const Stack<T>& otherStack): list(otherStack.list)
{
}
template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtTail(item);	
}

template <class T>
T Stack<T>::top()
{
	ListItem<T>* temp;
	temp = list.getTail();
	if (temp==NULL){
		return 0;
	}
	else{
		return temp->value;
	}

}
template <class T>
T Stack<T>::pop()
{
	ListItem<T>* temp;
	temp = list.getTail();
	T val;
    if (temp==NULL){
        return 0;
    }
    else{
       val = temp->value;
      // cout<<val<<endl;
       list.deleteTail();
       return val;
   	}

}

template <class T>
int Stack<T>::length()
{
	int len = list.length();
	return len;
}

template <class T>
bool Stack<T>::isEmpty()
{
	ListItem<T> *temp = list.getHead();
	if (temp==NULL){
		return false;
	}
	else{
		return true;
	}
}

#endif
