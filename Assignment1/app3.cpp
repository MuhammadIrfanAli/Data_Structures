#ifndef __APP3_CPP
#define APP3_CPP
#include "queue.cpp"
#include "app1.cpp"

Queue<string> FindWords(string sub_str)
{
	Queue<string> words;
	Dictionary();
	int subLen = strlen(sub_str.c_str()); 
	ListItem<string> *iter = dict.getHead();

	while (iter!=NULL){
		ListItem<string> *trav = iter->wordList.getHead();
		while (trav!=NULL){
			string travStr = trav->value;
			int travLen = strlen(travStr.c_str());
			if (subLen<travLen){ // only if sub length less.
				for (int i=0; i<=(travLen-subLen); i++){
					int match=0;
					for (int j=0; j<subLen; j++){
						if (sub_str[j]==travStr[i+j])
							match++;			
					}//for j.
					if (match==subLen){
						cout<<travStr<<endl;
						words.enqueue(travStr);
						match=0;
						break;
					}//if.			
				}//for i.
			}//if.
				
		trav = trav->next;
		}//while.		
	iter = iter->next;	
	}//while


}//function.

int main(){
	string inputStr;
	cout<<"Enter the sub_string to find the string/strings"<<endl;
	cin>>inputStr;
	FindWords(inputStr);

}//main.
#endif
