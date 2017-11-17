#ifndef __LIST_CPP
#define __LIST_CPP
#include <cstdlib>
#include "list.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List()
{
    head=NULL;
}

template <class T>
List<T>::List(const List<T>& otherList)
{
	head=NULL;
    ListItem<T>* oldTemp = otherList.head;
    ListItem<T>* tail = NULL;

    while (oldTemp){
        ListItem<T>* n = new ListItem<T>( oldTemp->value);

        if (!head) {
            head = n;
            tail = head;
        }
        else {
            tail->next = n;
            tail = n;
        }

        oldTemp = oldTemp->next;
    }
}
/*
	ListItem<T>* orgNode = otherList.head; //point to old nodes
	if (orgNode==NULL){
		return;
	}
	else{
	ListItem<T>* newNode = new ListItem<T>( orgNode->value); // new copied Node.
	ListItem<T>* temp;
	orgNode = orgNode->next;
	while (orgNode!=NULL){ //untill orgininal list gets finish.
		temp = newNode;
		ListItem<T>* newNode= new ListItem<T>( orgNode->value);
		temp->next = newNode;
		newNode->prev = temp;
		orgNode=orgNode->next;
	}
	newNode->next=NULL;
	}

}
*/
template <class T>
List<T>::~List()
{
/*	ListItem<T>* temp = head;
	if (head!=NULL){
		while (temp!=NULL){
			head = temp;
			temp = temp->next;
			delete head;
			head=NULL;
		}
	}//if.
	else{
		return;
	}	
*/
}

template <class T>
void List<T>::insertAtHead(T item)
{

      ListItem<T> *temp = new ListItem<T>(item);
      ListItem<T> *temp2=head;
        if (head!=NULL){
        	temp->next = temp2;
            temp2->prev = temp;
            head = temp;
        }//if.
        else{
        	temp->next=NULL;
            head = temp;
        }//else.

}


template <class T>
void List<T>::insertAtTail(T item)
{

	    ListItem<T> *temp = new ListItem<T>(item);
        ListItem<T> *temp2 = head;
        if (head!=NULL){ // Linked List is not empty.
            if (head->next==NULL){ // only one elem is present.
                head->next = temp;
                temp->prev = head;
                temp->next=NULL;
            }//if
            else{ // in case there are more than one elem present.
                while (temp2->next!=NULL)
                    temp2 = temp2->next;
                    temp2->next = temp;
                    temp->prev = temp2;
                    temp->next = NULL;
            }//else.

        }//if
        else{ // In Case linked list is empty.
			temp->next=NULL;
			head = temp;
        }//else.

}//func.

template <class T>
void List<T>::insertAfter(T toInsert, T afterWhat)
{
        ListItem<T> *temp = new ListItem<T>(toInsert);
        ListItem<T> *temp2 = head;
		ListItem<T> *post = temp2->next;
		if (head!=NULL){
				if (head->next==NULL && temp2->value==afterWhat){
					temp2->next=temp;
					temp->next=NULL;
					temp->prev = temp2;
				}
				else{ // more than one elements present.
					while (temp2!=NULL){
						if (temp2->value==afterWhat && temp2->next!=NULL){
							temp->next = temp2->next;
							post->prev = temp;
							temp2->next = temp;
							temp->prev = temp2;
							return;
						}//if
						else if(temp2->value==afterWhat && temp2->next==NULL){
							temp2->next = temp;
							temp->prev = temp2;
							temp->next=NULL;
							return;
						}//else if.
						temp2 = temp2->next;
						if(temp2->next!=NULL)
							post = temp2->next;
					}//while.
					return;
				}//else.	
		}
		else if(head==NULL){
			insertAtHead(toInsert);
		}

}

template <class T>
void List<T>::insertSorted(T item)
{

	ListItem<T> *insert = new ListItem<T>(item);
	ListItem<T> *trav = head;
	ListItem<T> *post;

    if (head!=NULL){
            if (item < head->value){
                insertAtHead(item);
                return;
            }//if.
            else if(item >= trav->value){// value greater than head.
            	while (trav->next!=NULL){
            		post=trav->next;
                	if ( item >= trav->value && item <= post->value ){
							insert->next = post;
                            post->prev = insert;
                            trav->next = insert;
                            insert->prev = trav;
                            return;
                	}//if.
                trav = trav->next;
                }//while.
                insertAtTail(item);
                return;
            }//else if
    }//if.
    else if(head==NULL){
    	insertAtHead(item);
    	return;
    }//else.

}

template <class T>
ListItem<T>* List<T>::getHead()
{
	return head;
}

template <class T>
ListItem<T>* List<T>::getTail()
{

	ListItem<T>* temp = head;
    if (head!=NULL){ // list not empty.
    	if (head->next==NULL){ // only one elem present.
     		return head;
     	}//if.
     	else{ // more than one elem present.
     		while (temp->next!=NULL)
     			temp = temp->next;
     			return temp;
     	}//else.
    }//if.
    else{ // list is empty.
        return NULL;
    }//else.

}

template <class T>
ListItem<T> *List<T>::searchFor(T item)
{

	ListItem<T> *temp = head;
	if (head!=NULL){
		while (item!=temp->value){
			if (temp->next==NULL){
				return NULL;
			}
			else{
				temp = temp->next;
			}
		}//while.
		if (temp->value==item){
			return temp;
		}

	}//if.
	else{
		return NULL;
	}//else.	
}

template <class T>
void List<T>::deleteElement(T item)
{

	if (head->value==item){
		deleteHead();
	}
	else if(head->value!=item){
		ListItem<T> *temp = head->next;
		while (temp!=NULL){
			if (temp->value == item && temp->next==NULL){
				deleteTail();
			}
			else if(temp->value == item && temp->next!=NULL){
				ListItem<T> *pre=temp->prev;
				ListItem<T> *post=temp->next;
				pre->next = post;
				post->prev=pre;
				delete temp;
				temp=NULL;
			}//else if.
			temp = temp->next;
		}//while.
	}

}

template <class T>
void List<T>::deleteHead()
{

	if (head!=NULL){
		ListItem<T> *temp = head;
		head = head->next;
		delete temp;
		temp=NULL;
	}

}

template <class T>
void List<T>::deleteTail()
{

	if (head!=NULL){
		ListItem<T> *temp = head;
		ListItem<T> *preTemp;
			while (temp->next!=NULL){
				preTemp = temp;
				temp = temp->next;
			}//while.
		preTemp->next=NULL;
		delete temp;
		temp=NULL;
	}//if

}

template <class T>
int List<T>::length()
{

	int count=0;
	ListItem<T> *temp = head;
			while (temp!=NULL){
				count++;
				temp = temp->next;
			}//while.
			return count;

}

#endif

