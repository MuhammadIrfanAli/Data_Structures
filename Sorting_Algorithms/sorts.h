#ifndef __SORTS_H
#define __SORTS_H
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ListItem{
	long data;
	long length;
	ListItem *next;
	ListItem *prev;
	ListItem(long entry){
		this->data = entry;
		this->next=NULL;
		this->prev = NULL;
	}
};
class List{
public:
	 ListItem *head;
	 ListItem *tail;
	 List();
	 void insertAtTail(long val);
	 void myQSL(ListItem* startP, ListItem* endP);
};

class hashItem{
	public:
		int data;	
	 	hashItem* next;
		hashItem(long k){
			this->data = k;
			this->next=NULL;
		}
};
class hashMap{
	public:
		hashItem **table;
		hashMap(int maxKey);
		void insert(long d);
};

vector<long> InsertionSort(vector<long> nums);
vector<long> MergeSort(vector<long> nums);
List Merge(ListItem* L,ListItem* R);
List SortList(List inputList);
vector<long> QuickSortArray(vector<long> nums);
void myQSA(long *num, long start, long end);
vector<long> QuickSortList(vector<long> nums);
vector<long> HeapSort(vector<long> nums);
void heapify(long array[], int n, long m);
vector<long> BucketSort(vector<long> nums, int max);
List MergeList(List inputList);

#endif
