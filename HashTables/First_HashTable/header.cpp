#include "header.h"



// Constructor.
hashMap::hashMap(){

	table = new hashItem*[cap];
	for (int i=0; i<cap; i++){
		table[i]=NULL;
	}//for.
}
// Destructor.
hashMap::~hashMap(){

}

// polynomial Hash Function.
int hashMap::polyHash(string val){
	int len = strlen(val.c_str());
	int sum=0; 
	for (int i=0; i<len; i++){
		int ascVal = static_cast<int>(val[i]);
		len--;
		sum = sum + (ascVal*(a^len)); 
	}
	sum = sum%cap;
	return sum;
}


// Get Key.
void hashMap::insert(string v){
	int retKey = polyHash(v);
	int i=retKey;
	
	if (table[i]==NULL){ 
		table[i] = new hashItem(retKey,v);	
	}
	else{
//		cout<<"comes here"<<endl;
		hashItem *trav = table[i];
		while ( trav->next!=NULL)
			trav = trav->next;	
			hashItem *temp = new hashItem(retKey,v);
			trav->next = temp;
	}		
}
// Search.......
int hashMap::search(string inputStr){
	int retKey = polyHash(inputStr);
	int i = retKey; 
	if (table[i]==NULL){
		return -1;
	}
	else{
		hashItem *trav = table[i];
		while (trav!=NULL){
			if (trav->getKey()==retKey && trav->getValue()==inputStr){
				return retKey;
			}
			trav = trav->next;
		}//while.
	}//else.
	return -1;
}// func....  







