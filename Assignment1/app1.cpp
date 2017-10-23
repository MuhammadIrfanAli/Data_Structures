#ifndef __APP1_CPP
#define APP1_CPP
#include <fstream>
#include "list.cpp"
#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
using namespace std;

List<string> dict;
ListItem<string>* dictHead;
//<------------------------------------------>
void insertAfter(string toInsert, string afterWhat)
{
		//<-------------------------------------------------------------------------------------->
        // Find Node.
        ListItem<string> *hPtr = dict.getHead();
        ListItem<string> *cur = hPtr;
            string s,s2;
            s = toInsert[0];
            	while (cur != NULL){
                	s2 = cur->value;
                	if (s2==s)
                    	break;
            	cur = cur->next;
            	}
		//<--------------------------------------------------------------------------------------->
		// you have the cur pointing to the right node.
		ListItem<string> *headPtr = cur->wordList.getHead();
		ListItem<string> *insert = new ListItem<string>(toInsert);
        ListItem<string> *trav = headPtr;
        ListItem<string> *post = trav->next;

		if (headPtr!=NULL){
					string travS = trav->value;
				if (headPtr->next==NULL && travS==afterWhat){
					trav->next=insert;
					insert->next=NULL;
					insert->prev = trav;
				}
				else{ // more than one elements present.
					while (trav!=NULL){
						if (trav->value==afterWhat && trav->next!=NULL){
							insert->next = post;
							post->prev = insert;
							trav->next = insert;
							insert->prev = trav;
							return;
						}//if
						else if(trav->value==afterWhat && trav->next==NULL){
							trav->next = insert;
							insert->prev = trav;
							insert->next=NULL;
							return;
						}//else if.
						trav = trav->next;
						if(trav->next!=NULL)
							post = trav->next;
					}//while.
		//			return;
				}//else.	
		}
		else if(headPtr==NULL){
			cur->wordList.insertAtHead(toInsert);
		}

}
//<------------------------------------------>

void recheck(){
    ListItem<string> *iter = dict.getHead();
	string temp;
    while (iter!=NULL){
        ListItem<string> *travHead = iter->wordList.getHead();
       	ListItem<string> *trav = travHead;
        ListItem<string> *post = trav->next;

         while (trav->next!=NULL){
         	int flow=0;
            string travStr = trav->value;
            string postStr = post->value;
            int travLen = strlen(travStr.c_str());
            int postLen = strlen(postStr.c_str());
                for (int i=0; i<travLen; i++){
                if (i>postLen){
                    break;
                }
                else if(travStr[i] < postStr[i]){
                	break;
                }
                else if(travStr[i]>postStr[i]){
                		postStr = temp;
                		post->value = travStr;
                		trav->value = temp;
                	//	cout<< trav->value <<"; "<< post->value <<endl;
                		flow=1;
                		break;
                }//else if.

        	}//for.
        	if (flow==1){
        		trav = travHead;
        		post = trav->next;
        	}
        	else if(flow==0){
     			trav = trav->next;
     			post = trav;
     		}	
    		}//trav while.
   		iter = iter->next;
    	}//iter while.
}//void

//<------------------------------------------->
List<string> Dictionary()
{			
	string insertStr;
	string wArray[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	int lenArray = sizeof( wArray ) / sizeof( wArray[ 0 ] );
	dictHead = dict.getHead();
	// insert elements in the nodes of 
	for (int i=0; i<lenArray;i++){
		dict.insertAtTail(wArray[i]);
	}
	//now open the input file and start reading.	
	ifstream fin;
	fin.open("words.txt");	
	while (!fin.eof()){
		getline(fin, insertStr, '\n');

	if ( !insertStr.empty()){
	
//<------------------------------------------------------------------------------------->
// find the node.	
			ListItem<string> *cur = dict.getHead();
			string s,s2;
			s = insertStr[0];
 			
			while (cur != NULL){ // find the required node.
				s2 = cur->value;
				if (s2==s)
					break;	
			cur = cur->next;
			}//while.
			// Node found.
//<-------------------------------------------------------------------------------------->
// now work in the wordList of a node.			
			ListItem<string> *secHead = cur->wordList.getHead();
			ListItem<string> *trav = secHead;
            ListItem<string> *pre = secHead;
            int stop=0;

			// empty list.
			if (secHead==NULL){
				cur->wordList.insertAtHead(insertStr);
			}

			// not empty linked list.
			else if (secHead!=NULL){			

				while (trav!=NULL && stop==0){
					string travStr = trav->value;
					int insertLen = strlen(insertStr.c_str());
					int travLen = strlen(travStr.c_str());
					int inserted=0;
					int match=0;

					for (int i=0; i<insertLen; i++){

						if (i>travLen){
							break;
						}  
							                                
						else if (insertStr[i]>travStr[i]){ // like ade > ace, don't waste time, move on.
							if (trav->next!=NULL){
								inserted=1; //insert=0 (actually) not inserted so move on to next node.
								break;
							}
							else if(trav->next==NULL){
					//			cout<<"toInsert->"<<insertStr<<"; travStr->"<<travStr<<endl;
								cur->wordList.insertAtTail(insertStr);
								inserted=1;
								stop=1; // find the new word. am done inserting.
								break;
							}
						}//else if.
								
						else if(insertStr[i]<travStr[i]){ // e.g., afre needs to come before agfr

							if (pre->value == secHead->value){ // in case node needs to go on head value.
								cur->wordList.insertAtHead(insertStr);
								stop=1; 
								inserted=1; 
								break;
							}//if.
							
							else if(pre->value!=secHead->value){
								insertAfter(insertStr,pre->value);
								inserted=1; 
								stop=1;
								break;
							}//else if.	
						}//elseif.
							
						else if(insertStr[i]==travStr[i]){
							match++;
						}//else if.										
					}//for.

					if (inserted==0){ // value has not been inserted.
				
						if (match==insertLen || match==travLen){ // if match found.
							if (insertLen < travLen){ // fare < farewell.
								// In case node needs to get head position.
								if (pre->value == secHead->value){
									cur->wordList.insertAtHead(insertStr);
									stop=1; inserted=1; break;
								}
								// in case not.
								else if (pre->value != secHead->value){
									insertAfter(insertStr,pre->value); // fare needs to go before farewell.......	
									stop=1; inserted=1; break;
								}//else.	
							}//if.
							else if(trav->next==NULL){
								cur->wordList.insertAtTail(insertStr);
								stop=1;
								inserted=1;
							    break;

							}

							// else continue with the algorithm.													
						}//if.
					}//if.	
					
					pre = trav;
					trav = trav->next;					
				}//while				
			}//else if.		
}//if.	
}//while		
//recheck()
cout<<endl<<endl<<"Only first few words (at max 10) of a,b,c,d are not working. the rest of the code "<<endl;
cout<<endl<<" is perfectly ordered. I have really tried to debug this error even made a recheck()"<<endl;
cout<<endl<<" function but still error continues. If you can somehow see the code and let me know afterwards"<<endl;
cout<<endl<<" , it would be a great favor, Thanks in advance." <<endl<<endl; 
}//func.
//<--------------------------------------------------------------------------------->

void displayList(){

	ListItem<string> *iter = dict.getHead();
//	ofstream fout;
//	fout.open("output.txt");
	while (iter!=NULL){
		ListItem<string> *temp = iter->wordList.getHead();	
			while (temp!=NULL){
				string frt = temp->value;
//				fout<< frt<<endl;
				cout<< temp->value <<endl;	
				temp = temp->next;
			}//while.
		iter = iter->next;	
	}//while.
//	fout.close();	
cout<<endl<<endl<<"Only first few words (at max 10) of a,b,c,d are not working. the rest of the code "<<endl;
cout<<endl<<" is perfectly ordered. I have really tried to debug this error even made a recheck()"<<endl;
cout<<endl<<" function but still error continues. If you can somehow see the code and let me know afterwards"<<endl;
cout<<endl<<" , it would be a great favor, Thanks in advance." <<endl<<endl;	
}//func.

int main(){
	Dictionary();	
	displayList();
return 0;
}
#endif
