#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include <cmath>

hashMap::hashMap(int maxKey){
	table = new hashItem*[maxKey];
	for (int i=0; i<maxKey; i++){
		table[i]=NULL;
	}//for.
}
//<=================================================================================>
List::List(){
	head = NULL;
	tail = NULL;
}
List quickList;
List mergeList;

//<--------------------------------------------------------------------------------->
vector<long> InsertionSort(vector<long> nums)
{

	long size = nums.size();
	long array[nums.size()];
	copy(nums.begin(),nums.end(),array);	
	long foo;


	for (int i=1; i<nums.size(); i++){
		foo=i;
		for (int j=i-1;j>=0;j--){
			if (array[foo] > array[j])
				break;				
			else if (array[foo] <= array[j]){
				int temp=array[j];
				array[j] = array[foo];
				array[foo] = temp;
				foo = j;
			}//if...
		}//for j..
	}//for i..
	vector <long> newVec;
	copy (array, array+nums.size(), back_inserter( newVec ) );
return newVec;

}
//<------------------------------------------------------------------------------------------------------>
vector<long> MergeSort(vector<long> nums)
{
	// base case.
	if (nums.size()<=1)
		return nums;	
	List finalList;
// copy all elements to linked list.
	for (int i=0 ;i<nums.size(); i++){
		mergeList.insertAtTail(nums[i]);
	}
	finalList = SortList(mergeList);
	nums.clear();
	ListItem *trav = finalList.head;
	while (trav!=NULL){
		nums.push_back(trav->data);
		trav = trav->next;
	}
	return nums;
}

//<---------------------------------------------------------------------------------------------------------->
List SortList(List inputList){
List leftList; List rightList; List resList;
// Make Left List......
	ListItem *trav = inputList.head;
if (trav->next!=NULL){
	ListItem *fastTrav = trav;

// Get to the middle of List....
	while (fastTrav!=NULL){
		fastTrav = fastTrav->next;
		if (fastTrav!=NULL){		
			fastTrav = fastTrav->next;
			leftList.insertAtTail(trav->data);	
			trav = trav->next;
		}		
	}
// Right List................
	while (trav!=NULL){
		rightList.insertAtTail(trav->data);
		trav = trav->next;
	}
}
else{
	return inputList;
}
	leftList = SortList(leftList);
	rightList = SortList(rightList);
	resList = Merge(leftList.head,rightList.head);
	return resList;
}
//<----------------------------------------------------------------------------------------------------------->
List Merge(ListItem* travL, ListItem* travR){

	List leftList; List rightList; List resList;
// Comparisons....
	while (travL!=NULL && travR!=NULL){

		if ( travL->data <= travR->data){
			resList.insertAtTail(travL->data);
			travL = travL->next;
		}	
		else{
			resList.insertAtTail(travR->data);
			travR = travR->next;	
		}				
	}
	
	while (travL!=NULL){
		 resList.insertAtTail(travL->data);
		 travL = travL->next;
	}
	while (travR!=NULL){
		 resList.insertAtTail(travR->data);
		 travR = travR->next;
	}
	return resList;

}
//<---------------------------------------------------------------------------------------------------->
void List::insertAtTail(long val){
		ListItem *temp = new ListItem(val);
        ListItem *temp2 = head;
        if (head!=NULL){ // Linked List is not empty.
            if (head->next==NULL){ // only one elem is present.
                head->next = temp;
                temp->prev = head;
                temp->next=NULL;
            }//if
            else{ // in case there are more than one elem present.
                while (temp2->next!=NULL)
                    temp2 = temp2->next;    
                temp2->next = temp;
                temp->prev = temp2;
                temp->next = NULL;
                tail = temp;
            }//else.

        }//if
        else{ // In Case linked list is empty.
			temp->next=NULL;
			head = temp;
        }//else.

}//func.

//<------------------------------------------------------------------------------------------------------->
vector<long> QuickSortArray(vector<long> nums)
{

	long initSize = nums.size();
	long array[initSize];
	copy(nums.begin(), nums.end(), array);
	myQSA(array,0,initSize-1);
	nums.clear();
	copy(array,array+initSize,back_inserter(nums));	
	return nums;
}

//<=========================================================================================================>

void myQSA(long array[], long startI, long endI){
	long temp;
	long pivot1 = array[startI]; 
	long pivot2 = array[endI]; 
	long ind = long(floor(startI+endI)/2);
	long pivot3 = array[long(floor(startI+endI)/2)];
	long pivot = pivot3;
// take MEdian of 3 Pivots....
	if (pivot3>=pivot1){ //10,15,30; 15,10,30
		if (pivot3>=pivot2 && pivot1>=pivot2)
			pivot = pivot1;
		else
			pivot = pivot2;	
	}
	else if (pivot1>=pivot2){ // 30,15,10; 30,10,15 
		if (pivot1>=pivot3 && pivot2>=pivot3)
			pivot = pivot2;
		else
			pivot = pivot3;	
	}
	else if (pivot2>=pivot1) // 10,30,15; 15,30,10.
		if (pivot2>=pivot3 && pivot1<=pivot3)
			pivot = pivot3;
		else
			pivot = pivot1;	
// Median Successfullll................	

	long lowerArrInd = startI;
	if (startI<endI){ // More than One elements present then StartHappy Coding.
		// get your Pivot at the start position.
		temp = array[startI];
		array[startI] = array[pivot];
		array[pivot] = temp; 
		pivot = startI;

		for (int i=int(startI+1); i<=int(endI); i++){
			if (array[i]<=array[startI]){ // Create L array.
				lowerArrInd+=1;
				// Swap.
				temp = array[lowerArrInd];
				array[lowerArrInd] = array[i];
				array[i] = temp;
			}
		}//for.
		// Give Pivot its proper position.....
		temp = array[pivot];
		array[pivot] = array[lowerArrInd];
		array[lowerArrInd] = temp;
		pivot = lowerArrInd;
		myQSA(array,startI,pivot-1);
		myQSA(array,pivot+1,endI);

	}//if.	
}
//<========================================================================================================>

vector<long> QuickSortList(vector<long> nums)
{

	long initSize = nums.size();

// insert elem in quickList
	for (int i=0; i<int(initSize); i++)
		quickList.insertAtTail(nums[i]);
	quickList.myQSL(quickList.head,quickList.tail);
	nums.clear();
	ListItem* trav = quickList.head;
	while(trav!=NULL){
		nums.push_back(trav->data);
		trav = trav->next;
	}
	return nums;
}

void List::myQSL(ListItem *leftEnd, ListItem *rightEnd){
 // Note that My node is random each time I swap///
	ListItem *startP;
	ListItem *trav; 
	long temp;
	
	if (leftEnd == rightEnd) return; // YOu have clashed, return..

	startP = leftEnd;
	trav = startP->next; // one node ahead..... 
	while (1){
		if (startP->data < trav->data){
// Swap the Nodes...........
			temp = trav->data;
			trav->data = startP->data;
			startP->data = temp;
		}	
		
		if (trav == rightEnd) break; // YOu are done Traversing through the Linked List.

		trav = trav->next; // set to next node.
	}


	temp = leftEnd->data;
	leftEnd->data = trav->data;
	trav->data = temp;

	ListItem *postTrav = trav;

	trav = trav->prev;
	if (trav != NULL){
		if ((leftEnd->prev != trav) && (trav->next != leftEnd))
			myQSL(leftEnd, trav);
	}

	trav = postTrav;
	trav = trav->next;
	if (trav != NULL){
		if ((trav->prev != rightEnd) && (rightEnd->next != trav))
			myQSL(trav, rightEnd);
	}
}
//<=======================================================================================>
vector<long> HeapSort(vector<long> nums)
{

	long initSize = nums.size();
	long curSize = initSize;
	long array[initSize];

	// copy elem into an array.....
	copy(nums.begin(), nums.end(), array);

	// First Build the Heap.........
	for (int i=int(floor(initSize/2)); i>=0; i--){
		heapify(array,i,initSize);
	}

	// Now the next step is to interchange the elements to take man elem at the end.;
	for (int i=int(curSize-1); i>=1; i--){
		long temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		curSize = curSize-1;
		heapify(array,0,curSize);	
	}	
	// copy elem back to vector.....
	nums.clear();
	copy(array, array+initSize, back_inserter(nums));
	return nums;
}
//<=======================================================================================>
void heapify(long array[], int parent, long size){

	int largest = parent;
	long leftC = 2*parent+1;
	long rightC = 2*parent+2;

	if ( leftC<size && array[leftC]>array[parent]){
		largest = leftC;
	}
	if ( rightC<size && array[rightC] > array[largest]){
		largest = rightC;
	}	
	if (largest!=parent){
		long temp = array[largest];
		array[largest] = array[parent];
		array[parent] = temp;	
		heapify(array, largest, size);
	}	
}
//<==================================================================================================>
void hashMap::insert(long ind){
//	int retKey = polyHash(v);
	
	if (table[ind]==NULL){ 
		table[ind] = new hashItem(ind);	
	}
	else{
		hashItem *trav = table[ind];
		while ( trav->next!=NULL)
			trav = trav->next;	
			hashItem *temp = new hashItem(ind);
			trav->next = temp;
	}		
}

//<============================================================================================>

vector<long> BucketSort(vector<long> nums, int max){

// I have made Max Function inside the Generator FILE......
//	max=0;
	long bucketSize = nums.size();
//	for (int i=0; i<nums.size(); i++){
//		if (max < nums[i])
//			max = nums[i];
//	}
	max = max+1;
	hashMap buckets(max);
	for (int i=0; i<nums.size(); i++){
		buckets.insert(nums[i]);
	}
	nums.clear();
	
	for (int i=0; i<max; i++){
		if (buckets.table[i]!=NULL){
			hashItem* trav = buckets.table[i]; 
			while (trav!=NULL){
				nums.push_back(trav->data);
				trav = trav->next;
			}	
		}
	}
	return nums;
}
//<============================================================================================>
#endif
