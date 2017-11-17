#ifndef __LIST_CPP
#define __LIST_CPP
#include <cstdlib>
#include "header.h"
#include <iostream>
#include <vector>
using namespace std;


template <class A, class B>
tree<A,B>::tree()
{

    root=NULL;
}

template <class A, class B>
tree<A,B>::~tree()
{

}

//<------------------------------------------------->
// make new node.
template <class A, class B>
treeNode<A,B> *tree<A,B>::newNode(A v, B k){
	treeNode<A,B> *toInsert = new treeNode<A,B>(v,k);
	toInsert->left=NULL;
	toInsert->right=NULL;
//	cout<< k<<endl;
	return toInsert;
}
//<------------------------------------------------->
// insert
template <class A, class B>
void tree<A,B>::insert(A v, B k)
{

	treeNode<A,B> *trav = root;
	if (root==NULL){
		root = newNode(v,k);
	}//if,
	else{
		while (trav!=NULL){
			if (k < trav->key){ 
				if(trav->left==NULL){
					trav->left = newNode(v,k);
					return;
				}	
				else{
					trav = trav->left;
				}
			}//if.			
			else if (k > trav->key){
				 if (trav->right==NULL){
				 	 trav->right = newNode(v,k);
				 	 return;
				 }
				 else{
				 	trav = trav->right;
				 }
			}//elseif.	 				
		}//while.	

	}//else.
}// insert func.
//<------------------------------------------------>
template <class A, class B>
treeNode<A,B> *tree<A,B>::search(B item)
{
	if(root!=NULL){
		treeNode<A,B> *trav = root;
		while (trav!=NULL){
		// Go left if item is less than or equal.
			if (item <= trav->key){
				if (item==trav->key){
					cout<<  trav->key <<endl;
					return trav;
				}//if.	
				else
				trav = trav->left;	
			}//if..
			else if(item >= trav->key){
				if (item==trav->key){
					cout<< trav->key<<endl;
					return trav;
				}	
				else
					trav = trav->right;
			}//else if.
		}//while.
		return NULL; 
	}//if.
}// search func.
//<------------------------------------------------>
template <class A, class B>
treeNode<A,B> *tree<A,B>::parent(B item)
{
    if(root!=NULL){
        treeNode<A,B> *trav = root;
		treeNode<A,B> *pre = trav;
        while (trav!=NULL){
        // Go left if item is less than or equal.
            if (item <= trav->key){
                if (item==trav->key){ 
                    return pre;
                }
                else{
                	pre = trav;
                	trav = trav->left;
                }
            }//if..
            else if(item >= trav->key){
                if (item==trav->key){
                    return pre;
                }    
                else{
                	pre = trav;
                    trav = trav->right;
                }  
            }//else if.
        }//while.
    }//if.
}// search func.

//<-------------------------------------------------------------------------------------------->
template <class A, class B>
void tree<A,B>::deleteNode(B item)
{
	treeNode<A,B> *retNode = search(item);
if (retNode!=NULL){	
	treeNode<A,B> *retParent = parent(item);
	treeNode<A,B> *parentLeft = retParent->left;
	treeNode<A,B> *parentRight = retParent->right;
	// If Node has no subtree.
//if (retNode!=NULL){	
	
	if (retNode->left==NULL && retNode->right==NULL){
		cout<<"case1"<<endl;
		if (parentLeft!=NULL && parentLeft->key==retNode->key){ // Node at the left of parent.
			retParent->left=NULL;
			delete(retNode);
			retNode=NULL;
			cout<<endl<<"Key Successfully Deleted!!"<<endl;
			return;
		}//if.	
		else if(parentRight!=NULL && parentRight->key==retNode->key){ // Node is at the right of parent.
			retParent->right=NULL;
			delete(retNode);
			retNode=NULL;
			cout<<endl<<"Key Successfully Deleted!!"<<endl;
			return;	
			
		}//else if.	
	}//if.
	// if Node deleted has only one subtree.
	else if (retNode->left==NULL){
		 cout<<"case2"<<endl;
		if (parentLeft!=NULL && parentLeft->key==retNode->key){ // Node is at the left of parent.
			retParent->left = retNode->right; 
		}
		else if(parentRight!=NULL && parentRight->key==retNode->key){ // Node is at the right of parents.
			retParent->right= retNode->right;
		}			
		delete(retNode);
		retNode=NULL;
		cout<<endl<<"Key Successfully Deleted!!"<<endl;
		return;
	}
	else if(retNode->right==NULL){
		 cout<<"case3"<<endl;
		if (parentLeft!=NULL && parentLeft->key==retNode->key){ // Node is at the left of parent	
			retParent->left = retNode->left;
		}
		else if(parentRight!=NULL && parentRight->key==retNode->key){ // node is at the right of parent.
			retParent->right = retNode->left;
		}
		delete(retNode);
		retNode=NULL;
		cout<<endl<<"Key Successfully Deleted!!"<<endl;
		return;
	}		
	// if Node has both subtree.
	else if(retNode->left!=NULL && retNode->right!=NULL){
		cout<<"case4"<<endl;
		treeNode<A,B> *nodeRight = retNode->right;
		treeNode<A,B> *preN=nodeRight;
		while (nodeRight->left!=NULL){
			preN = nodeRight;
			nodeRight = nodeRight->left;
		}//while.
		A a1 = nodeRight->value;
		B b1 = nodeRight->key;
		preN->left=NULL;
		delete(nodeRight);
		nodeRight=NULL;
		retNode->value = a1;
		retNode->key = b1;
		cout<<endl<<"Key Successfully Deleted!!"<<endl;
	
	}//else if.
}
else
	cout<<"Either Key deleted previously or it is not present in the tree!!"<<endl;
}// delete func.
//<----------------------------------------------------------------------->
template <class A, class B>
treeNode<A,B> *tree<A,B>::getRoot(){
	return root;
}
//<------------------------------------------------------------------------>

template <class A, class B>
int tree<A,B>::height( treeNode<A,B> *h){
	  
    if(h==NULL)
 		return -1;
    else{

        int leftH=height(h->left);

        int rightH=height(h->right);

        if (leftH>rightH){
        	leftH=leftH+1;
        	return leftH;
        }

        else{
            rightH=rightH+1;
            return rightH;

        }//else.
    }//else.

}
#endif
