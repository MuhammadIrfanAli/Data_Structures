#include "header.cpp"
#include "time.h"
#include <fstream>
#include <sstream>

//tree<string> bst; 
int main(){
	tree <string, int> bst;
	ifstream fin;
	fin.open("pairs.txt");
	
	while (!fin.eof()){
		string tempStr, s1, s2;
	
		vector<string> vec;
		getline(fin, tempStr);

		istringstream iss(tempStr);
		while (getline(iss, tempStr, '~'))
			vec.push_back(tempStr);
					
		s1 = vec[0];
		s2 = vec[1];
		int k= atoi(s2.c_str());
		bst.insert(s1,k);

	
	}// read while.	
	while (1){
		string value, s1;
		int key, newKey, oldKey, c;
		treeNode<string,int > *r = bst.getRoot();
		
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
				bst.insert(value, key);
				cout<<endl<<"pair successfully inserted"<<endl;
				stopTimer();			
				}
			else if(c==2){
				cout<<"Enter the key: ";
				cin>>key;
				treeNode<string,int> *retNode = bst.search(key);
				if (retNode!=NULL){
					cout<<"Value found is: "<< retNode->value<<endl;
				}
				else{
					cout<<"value not found. The Programme will Terminate."<<endl;
					break;
				}		
			
			}	
			else if(c==3){
				cout<<"Enter key: ";
				cin>>key;
				startTimer();
				bst.deleteNode(key);
				stopTimer();
			}
			else if(c==4){
				cout<<"Enter new key: "; cin>>newKey;
				cout<<"Enter key you want to replace: "; cin>>oldKey;
				treeNode<string, int> *n = bst.search(newKey);
				treeNode<string, int> *n2 = bst.search(oldKey);
				if (n==NULL){
					if (n2==NULL){
						cout<<"Old Key you want to be replaced by, does not exist"<<endl;
					}
					else{
						s1 = n2->value; 
						bst.deleteNode(oldKey);
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
				int h = bst.height(r);		
				cout<<"Current height of tree is: "<<h<<endl;
			}
			else if(c==0){
			 return 0; 
			}	
			else{
				continue;
			}
	
	}// cases while.


}//main.
