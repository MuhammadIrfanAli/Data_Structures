
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
    int nodeHeight;
    treeNode<A,B> *left;
    treeNode<A,B> *right;

    treeNode(A theVal, B theKey)
    {
        this->value = theVal;
        this->key = theKey;
        this->nodeHeight = 0;
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
    treeNode<A,B> *insert(A item1, B item2);
	treeNode<A,B> *insert(treeNode<A,B> *&temp, A item, B item1);
	
	void rotateRightOnce( treeNode<A,B> *&temp);
	void rotateLeftOnce( treeNode<A,B> *&temp);
	void rotateRightTwice( treeNode<A,B> *&temp);
	void rotateLeftTwice( treeNode<A,B> *&temp);
	
	void checkLeftBalance( treeNode<A,B> *&temp, B item);
	void checkRightBalance( treeNode<A,B> *&temp, B item);
	void updateHeight(treeNode<A,B> *&temp, B item);

	void assignHeights( treeNode<A,B> *&temp);

	treeNode<A,B> *traverse( treeNode<A,B> *&temp);
    treeNode<A,B> *newNode(A item1, B item2);
    treeNode<A,B> *getRoot();

    treeNode<A,B> *search( treeNode<A,B> *&temp, B key);
    treeNode<A,B> *parent(B key);

    treeNode<A,B> *deleteNode(B key);
    int height(treeNode<A,B> *&h);
};
#endif
