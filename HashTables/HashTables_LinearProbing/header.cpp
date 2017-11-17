#include "header.h"
#include <cstdlib>

int size=0;
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
	float lamda = (double(size))/cap; 
//	cout<<lamda<<endl;
	if (lamda >=0.6){
		resize();
//		cout<<"Being ReSizex"<<endl;
	}
	while (table[i]!=NULL){
		i=(i+1)%cap;
	}	
		table[i] = new hashItem(retKey,v);	
		size++;	
//	if (v=="A's"){
//		cout<<"Key is: "<<retKey<<" with index "<<i<<endl;
//	}	
}
// Search.......
int hashMap::search(string inputStr){
	int retKey = polyHash(inputStr);
	int i = retKey;
	int iter=0;
//	if (inputStr=="A's"){
//		cout<< "retKey is: "<<retKey<<" and cap is: "<<cap <<endl;
//	}	
		while (iter<cap){
			hashItem *trav = table[i];
			if ( trav!=NULL && trav->getValue()==inputStr)
				return trav->getKey();
			i = (i+1)%cap;
			iter++;
//			if (i==40){
//				cout<<"Key is: "<< trav->getKey()<< " and value is: "<< trav->getValue()<<endl;
//				break;
//			}
//		cout<<"iterating "<<iter<<"th Time at Index "<<i<<endl;	
		}//while.
	return -1;
}// func....  
// Resize

void hashMap::resize(){
//	hashItem *trav = table[cap-1];
//	hashItem *table
	int oldCap = cap;
	int newCap = cap*2;
	hashItem **oldTable = table;
	table = new hashItem*[newCap];
//	size_t newSize = size * 2;
   // 	table = new hashItem*[newCap];
	//]int* newArr = new int[newSize];
//		memcpy(table, oldTable, cap * sizeof(int) );
 //   	trav = (hashItem*) realloc( trav, cap * sizeof(int) );
 //		for (int i=cap; i<newCap; i++)
//			table[i]=NULL;
 //   	cap = newCap;
 //   	delete [] oldTable;
   // 	arr = newArr;


//	table = new hashItem*[cap];
	for (int i=oldCap; i<newCap; i++)
		table[i] = NULL;
	for (int i=0; i<oldCap; i++){ // cap is now 2*(old)cap....remember.
		hashItem *trav = oldTable[i];
		if (trav!=NULL){ // only if data has been hashed at this index.
			int tempK = trav->getKey();
			string tempStr = trav->getValue();
			table[i] = new hashItem(tempK,tempStr);
		}
		else{
			table[i] = NULL;
		}
		delete trav;
	}	
	delete [] oldTable;
	cap = newCap;	
}
