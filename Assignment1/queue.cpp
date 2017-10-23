#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
}
    
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue): list(otherQueue.list)
{
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
	T val;
	ListItem<T>* temp = list.getHead();
	val = temp->value;
	return val;
}

template <class T>
T Queue<T>::dequeue()
{
	T val;
	ListItem<T> *temp = list.getHead();
	if (temp==NULL){
		return 0;
	}
	else{
		val = temp->value;
		list.deleteHead();
		return val;
	}
}

template <class T>
int Queue<T>::length()
{
	int len;
	return len = list.length();
}

template <class T>
bool Queue<T>::isEmpty()
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
