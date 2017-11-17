#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
int cap = 100;
const int a=37;

class hashItem{
	public:
		int key;
		string value;
	public:	
	 	hashItem* next;
		hashItem(int k, string v){
			this->key = k;
			this->value = v;
			this->next=NULL;
		}
	int getKey(){
		return key;
	}	
	string getValue(){
		return value;
	}
};
class hashMap{
	private:
		hashItem **table;
	public:
		hashMap();
		~hashMap();
		int polyHash(string val);
		void insert(string val);
		int search(string val);
		void resize();
};

