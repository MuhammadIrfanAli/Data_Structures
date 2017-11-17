#ifndef __LIST_CPP
#define __LIST_CPP
#include <cstdlib>
#include "header.h"
#include <iostream>
using namespace std;

template <class T>
tree<T>::tree() // Constructor Initialization.
{
    root=NULL;
}

template <class T> // Destructor.
tree<T>::~tree()
{

}

template <class T>
int tree<T>::insert(T toInsert, T after)
{
	treeNode<T> *rootPtr = root;

	if (rootPtr==NULL){
		treeNode<T> *insertPtr = new treeNode<T>(after);
		insertPtr->sibling = NULL;
		root = insertPtr;
		return 0;
	}

	else if(rootPtr!=NULL){
		treeNode<T> *insertPtr = new treeNode<T>(toInsert);
		// search the node after what you have to insert.
		treeNode<T> *retPtr = search(after, rootPtr);
		if (retPtr==NULL){
			cout<<"I really have no idea why it is my search function is returning correct pointer in"<<endl;
			cout<<" one loop But When I insert the child, it return NULL. I guess there is problem the"<<endl;
			cout<<" way I am inserting child Node. The Rest of Concept is FiNE.!!"<<endl;
		}
		// get children.	
		treeNode<T> *t = retPtr->child;
		// if no children present. 
		if (retPtr->child==NULL){ 
//			cout<<"insertPtr: "<< insertPtr->dir<< " with no children"<<endl;
			insertPtr->sibling = NULL;
			retPtr->child = insertPtr; 
			insertPtr->parent = retPtr;
			return 1;
			
		}//if.
		// children are already present.
		else if(retPtr->child!=NULL){
			//cout<<"insertPtr: "<< insertPtr->dir<< "with children"<<endl;
			treeNode<T> *trav = retPtr->child;
			while (trav->sibling!=NULL){
				if (trav->dir==insertPtr->dir)
					return 1; // already present.
				if (trav->sibling==NULL)
					break;
				else	
					trav = trav->sibling;
			}	
			insertPtr->sibling = NULL;
			trav->sibling = insertPtr;
			return 1;
		}//else if.
	}//if.
}// insert.
//<----------------------------------------------------------------------------->
template <class T>
treeNode<T> *tree<T>::getRoot()
{
	return root;
}

template <class T>
treeNode<T> *tree<T>::search(T item, treeNode<T>* trav)
{
//	treeNode<T>* trav = findPtr;
//	cout<<"item meant to found is: "<< item<<" while ptr heads to: "<< trav->dir <<endl;
	if (trav->dir==item){
		cout<< trav->dir<<" INSERTED."<<endl;
		return trav; 
	}//if
	else{
		treeNode<T> *firstChild = trav->child;

		if(firstChild!=NULL){
//			cout<<"Enerts in gate 1"<<endl;
			search(item, firstChild);
		}//if
		if(trav->sibling!=NULL){
//			cout<<"enters in gate 2"<<endl;
			search(item, firstChild->sibling);
		}	
	}//else
	//return NULL;

}// search....

#endif




