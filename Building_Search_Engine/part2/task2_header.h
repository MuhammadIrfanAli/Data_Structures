#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>
#include <cstring>
#include <vector>

/* This class just holds a single data item. */
template <class A, class B>
struct treeNode{
    A value;
    B key;
    treeNode<A,B> *left;
    treeNode<A,B> *right;

    treeNode(A theVal, B theKey)
    {
        this->value = theVal;
        this->key = theKey;
        this->left = NULL;
        this->right = NULL;
    }
};
/* This is the generic List class */
template <class A, class B>
class tree
{
    treeNode<A,B> *root;

public:
    tree();
    ~tree();
    void insert(A item1, B item2);
    treeNode<A,B> *newNode(A item1, B item2);
    treeNode<A,B> *getRoot();
    treeNode<A,B> *search(B key);
    treeNode<A,B> *parent(B key);
    void deleteNode(B key);
    int height(treeNode<A,B> *h);
};
#endif
