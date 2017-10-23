#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>
#include <cstring>
#include <vector>
/* This class just holds a single data item. */
template <class T>
struct ListItem;
/*
{
    T value;
    ListItem<T> *next;
    ListItem<T> *prev;
//    List< list<string> > wordList;

    ListItem(T theVal)
    {
        this->value = theVal;
        this->next = NULL;
        this->prev = NULL;
    }
};
/* This is the generic List class */
template <class T>
class List
{
    ListItem<T> *head;

public:

    // Constructor
    List();

    // Copy Constructor
    List(const List<T>& otherList);

    // Destructor
    ~List();

    // Insertion Functions
    void insertAtHead(T item);
    void insertAtTail(T item);
    void insertAfter(T toInsert, T afterWhat);
    void insertSorted(T item);

    // Lookup Functions
    ListItem<T> *getHead();
    ListItem<T> *getTail();
    ListItem<T> *searchFor(T item);

    // Deletion Functions
    void deleteElement(T item);
    void deleteHead();
    void deleteTail();

    // Utility Functions
    int length();
};
template <class T>
struct ListItem
{
	T value;
    ListItem<T> *next;
    ListItem<T> *prev;
    List<T> wordList;
    ListItem(T theVal)
    {
        this->value = theVal;
        this->next = NULL;
        this->prev = NULL;
    }

};

#endif
