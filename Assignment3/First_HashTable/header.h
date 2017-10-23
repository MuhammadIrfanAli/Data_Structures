#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
const int cap = 1000;
const int a=50;

class hashItem{
	private:
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
};

