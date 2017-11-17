#include <iostream>
#include <vector>
#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;


/* This class just holds a single data item. */
template <class T>
struct treeNode{

    T dir;
    treeNode<T> *sibling;
    treeNode<T> *parent;
    treeNode<T> *child;
//    tree<T> children;
    treeNode(T theDir){
        this->dir = theDir;
        this->sibling = NULL;
        this->parent = NULL;
        this->child = NULL;
    }



};

/* This is the generic List class */

template <class T>
class tree
{
    treeNode<T> *root;

public:

    tree();
    ~tree();
    int insert(T s1, T s2);
    treeNode<T> *getRoot();
    treeNode<T> *search(T item, treeNode<T> *ptr);
};
#endif

