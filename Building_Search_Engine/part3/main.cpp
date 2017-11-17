#include "avl.cpp"
#include "time.h"
#include <fstream>
#include <sstream>

//tree<string> bst; 
int main(){
	tree <string, int> bst;
	ifstream fin;
	int check=0;
//	int flag=0;
//<-------------------------------------------------------------------->
					// Choose File.
//<-------------------------------------------------------------------->	
	while (1){
	cout<<"CHOOSE between Files"<<endl;
	cout<<"1_names.txt"<<endl;
	cout<<"2_pairs.txt"<<endl;
	cin>>check;
		if (check==1){
			fin.open("names.txt");
			break;
		}
		else if (check==2){
			fin.open("pairs.txt");
			break;
		}
		else{
			cout<<"In-Correct Command"<<endl;
			continue;
		}
	}
//<---------------------------------------------------------------------->
					// Choose Data Type.
//<---------------------------------------------------------------------->
	while (1){
		cout<<"Pleas Choose Data Structure:"<<endl;
		cout<<"1_BST"<<endl;
		cout<<"2_AVL"<<endl;
		cin>>flag;
		if (flag==1 && check==2){
			cout<< "Be patient!"<<endl;
			break;
		}
		else if (flag==2 && check==2){
			cout<< "With 'pairs.txt', there is no segmentation fault. Code is absolutely working But there are 1 billion entries "<<endl;
			cout<< "so it takes too much time delay which makes AVL useless for such a large data. I can't understand why it is "<<endl;
			cout<< "not working for AVL. Code is standard Based with single and double Left and Right Rotations. you can also have "<<endl;
			cout<< "a look at the code. It is perfect as far as I know. If you can figure out why it is happening, please do let me know."<<endl;
			cout<< "Just in case, this green Bar is still reading the data, but rotation I guess have become complex. It is performing them "<<endl;
			cout<< "again and again. So toooooooo MUch DeLAy here Zzzzzzzzz!!!!!!"<<endl;
 			break;
		}
		else if (flag==1 || flag==2)
			break;
		else{
			cout<<"In_Correct Command"<<endl;
			continue;
		}	
	}
//<---------------------------------------------------------------------->
					// Now Start Happy Coding :)
//<---------------------------------------------------------------------->
	treeNode<string,int > *rootNode = bst.getRoot();
//                     Start Reading From File.
	while (!fin.eof()){
		string tempStr, s1, s2;
		vector<string> vec;
		getline(fin, tempStr);
		istringstream iss(tempStr);

		while (getline(iss, tempStr, '~'))
			vec.push_back(tempStr);
			
		s1 = vec[0];
		s2 = vec[1];
		int k = atoi(s2.c_str());
		bst.insert(s1,k);
	
	}// read while.	 
	bst.assignHeights(rootNode);
//<----------------------------------------------------------------------->
// 						USER INTERFACE
//<----------------------------------------------------------------------->

	while (1){
		string value, s1;
		int key, newKey, oldKey, c;
		treeNode<string,int > *rootNode = bst.getRoot();
		cout<<"Enter 1 to insert key/value pair"<<endl;
		cout<<"Enter 2 to search a key with its value"<<endl;
		cout<<"Enter 3 to delete key/value pair"<<endl;
		cout<<"Enter 4 to update an existing key/value pair"<<endl;
		cout<<"Enter 5 to see the current height of the tree"<<endl;
		cout<<"Enter 0 to exit"<<endl; 
		cin>>c;
			if (c==1){
				cout<<"Enter value: "; cin>>value;
				cout<<"Enter key: "; cin>>key;
				startTimer();
				treeNode<string, int> *temp = bst.search(rootNode, key);
				bst.insert(value, key);
				cout<<endl<<"pair successfully inserted"<<endl;	
				stopTimer();			
			}
			else if(c==2){
				cout<<"Enter the key: ";
				cin>>key;
				treeNode<string,int> *retNode = bst.search(rootNode, key);
				if (retNode!=NULL){
					cout<<"Value found is: "<< retNode->value<<endl;
				}
				else if (retNode==NULL){
					cout<<"value not found. The Programme will Terminate."<<endl;
					break;
				}		
			
			}	
			else if(c==3){
				cout<<"Enter key: ";
				cin>>key;
				startTimer();
				treeNode<string, int> *rand = bst.deleteNode(key);
				if (flag==2 && rand!=NULL){
					bst.updateHeight(rand,key);
					cout<<"Operation Successful!"<<endl;
					 stopTimer();	
				}
				else if (rand==NULL)
					cout<< "Either Old Key not found or New key already exists.!"<<endl;
			}
			else if(c==4){
				cout<<"Enter new key: "; cin>>newKey;
				cout<<"Enter key you want to replace: "; cin>>oldKey;
				treeNode<string, int> *n = bst.search(rootNode, newKey);
				treeNode<string, int> *n2 = bst.search(rootNode, oldKey);
				if (n==NULL){
					if (n2==NULL){
						cout<<"Old Key you want to be replaced by, does not exist"<<endl;
					}
					else{
						s1 = n2->value; 
						treeNode<string,int > *rand = bst.deleteNode(oldKey);
						if (flag==2 && rand!=NULL){
							bst.updateHeight(rand, oldKey);
						}
						bst.insert(s1, newKey);
						cout<<endl<<"Operation successful"<<endl;
					}
				}
				else{
					cout<<"key already in use. The Programme will terminate.!"<<endl;
					break;
				}
			}
			else if(c==5){
				treeNode<string,int > *r1 = bst.getRoot();
				int h = bst.height(r1);		
				cout<<"Current height of tree is: "<<h<<endl;
			}
			else if(c==0){
			 return 0; 
			}	
			else{
				continue;
			}
	cin.ignore();
	}// cases while.
}//main.
