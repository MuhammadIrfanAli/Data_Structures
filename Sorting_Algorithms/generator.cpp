#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include "sorts.cpp"
#include <fstream>

using namespace std;

/* Number theory to the rescue.
 * Generates a permutation of [0 .. d-1]
 * Where n<d and both are prime
 */

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
vector<long> GenerateRandom(long n, long d);
vector<long> GenerateSorted(long n);
vector<long> GenerateReverseSorted(long n);
vector<long> GenerateAlmostSorted(long n, int s);

bool CheckSorted(vector<long> nums);
int insertionTesting();
int mergeTesting();
int quickArrayTesting();
int quickListTesting();
int heapTesting();
int bucketTesting();

int main(int argc, char *argv[])
{
    ofstream fout;
    fout.open ("/home/mohsin/FsortingGrade.txt", fstream::in | fstream::out | fstream::app);
    char* input=argv[1];
    cout<<"input is "<<input[0]<<" "<<input[1]<<endl;
    int score=0;
    if(input[0]=='1')
    {
    	cout<<"yes its 1"<<endl;
	score=insertionTesting();
    }

	if(input[0]=='2'){
		score=mergeTesting();
		cout <<"Score_2: "<<score<<endl;
	}
	if(input[0]=='3'){
		score=quickArrayTesting();
		cout <<"Score_3: "<<score<<endl;
		
	}	
	if(input[0]=='4'){
		score=quickListTesting();
		cout <<"Score_4: "<<score<<endl;
		
	}	
	if(input[0]=='5'){
		score=heapTesting();
	
	cout <<"Score_5: "<<score<<endl;
	}
	if(input[0]=='6'){
		score=bucketTesting();
		cout <<"Score_6: "<<score<<endl;
		
	}	

	fout<< score <<endl;


	return 0;
}

bool CheckSorted(vector<long> nums)
{
	int vecSize = nums.size();
	for(int i=0; i<vecSize-1; i++)
	{
		if(nums[i] > nums[i+1])
		{
			return false;
		}
	}
	return true;
}

int numErrors(vector<long> nums)
{
	int vecSize = nums.size();
	for(int i=0; i<vecSize-1; i++)
	{
		if(nums[i] > nums[i+1])
		{
			return false;
		}
	}
	return true;
}

int insertionTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Insertion Sort"<<endl;
	cout<<"*********************"<<endl;

	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);
	int score=0;
	vector<long> outVec = InsertionSort(randVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Random Works"<<endl;
		score++;
	}

	outVec = InsertionSort(sortVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Sorted Works"<<endl;
		score++;
	}

	outVec = InsertionSort(reverseVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Reverse Works"<<endl;
		score++;
	}

	outVec = InsertionSort(almostVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Almost Works"<<endl;
		score++;
	}
	cout<<"score was "<<score<<endl;
	return score;
}

int mergeTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Merge Sort"<<endl;
	cout<<"*********************"<<endl;

	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);
	int score=0;
	vector<long> outVec = MergeSort(randVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Random Works"<<endl;
score++;
	}

	outVec = MergeSort(sortVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Sorted Works"<<endl;
		score++;
	}

	outVec = MergeSort(reverseVec);
	if( CheckSorted(outVec) )
	{
	score++;	cout<<"Reverse Works"<<endl;
	}

	outVec = MergeSort(almostVec);
	if( CheckSorted(outVec) )
	{
	score++;	cout<<"Almost Works"<<endl;
	}
	return score;
}

int quickArrayTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Quick Sort (array)"<<endl;
	cout<<"*********************"<<endl;
	int score =0;
	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);

	vector<long> outVec = QuickSortArray(randVec);
	if( CheckSorted(outVec) )
	{
		cout<<"Random Works"<<endl;
		score++;
	}

	outVec = QuickSortArray(sortVec);
	if( CheckSorted(outVec) )
	{
	score++;	cout<<"Sorted Works"<<endl;
	}

	outVec = QuickSortArray(reverseVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Reverse Works"<<endl;
	}

	outVec = QuickSortArray(almostVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Almost Works"<<endl;
	}

	return score;
}

int quickListTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Quick Sort (list)"<<endl;
	cout<<"*********************"<<endl;

	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);
	int score =0;
	vector<long> outVec = QuickSortList(randVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Random Works"<<endl;
	}

	outVec = QuickSortList(sortVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Sorted Works"<<endl;
	}

	outVec = QuickSortList(reverseVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Reverse Works"<<endl;
	}

	outVec = QuickSortList(almostVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Almost Works"<<endl;
	}
	return score;
}

int heapTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Heap Sort"<<endl;
	cout<<"*********************"<<endl;

	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);
	int score=0;
	vector<long> outVec = HeapSort(randVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Random Works"<<endl;
	}

	outVec = HeapSort(sortVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Sorted Works"<<endl;
	}

	outVec = HeapSort(reverseVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Reverse Works"<<endl;
	}

	outVec = HeapSort(almostVec);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Almost Works"<<endl;
	}
	return score;
}

int bucketTesting()
{
	cout<<"*********************"<<endl;
	cout<<"Bucket Sort"<<endl;
	cout<<"*********************"<<endl;
	int score=0;
	vector<long> randVec = GenerateRandom(3233, 10000);
	vector<long> sortVec = GenerateSorted(10000);
	vector<long> reverseVec = GenerateReverseSorted(10000);
	vector<long> almostVec = GenerateAlmostSorted(10000, 323);

	vector<long> outVec = BucketSort(randVec, 12345);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Random Works"<<endl;
	}

	outVec = BucketSort(sortVec, 12345);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Sorted Works"<<endl;
	}

	outVec = BucketSort(reverseVec, 12345);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Reverse Works"<<endl;
	}

	outVec = BucketSort(almostVec, 12345);
	if( CheckSorted(outVec) )
	{
		score++;
		cout<<"Almost Works"<<endl;
	}
	return score;
}

vector<long> GenerateRandom(long n, long d)
{
    vector<long> nums;
    long k, residue;
    for (k = 0; k < d; k++)
    {
        residue = (long) (((long long)k * (long long) n) % d);
        nums.push_back(residue);
    }
    return nums;
}

vector<long> GenerateSorted(long n)
{
    vector<long> nums;
    for (long k = 0; k < n; k++)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateReverseSorted(long n)
{
    vector<long> nums;
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateAlmostSorted(long n, int s)
{
    vector<long> nums;
    srand ( time(NULL) );
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    int k1, k2;
    long tmp;
    for (size_t i = 0; i < s; i++)
    {
        k1 = rand() % n;
        k2 = rand() % n;
        tmp = nums[k2];
        nums[k2] = nums[k1];
        nums[k1] = tmp;
    }
    return nums;
}

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{

        /* Perform the carry for the later subtraction by updating y. */
        if (x->tv_usec < y->tv_usec)
        {
                int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
                y->tv_usec -= 1000000 * nsec;
                y->tv_sec += nsec;
        }
        if (x->tv_usec - y->tv_usec > 1000000)
        {
                int nsec = (x->tv_usec - y->tv_usec) / 1000000;
                y->tv_usec += 1000000 * nsec;
                y->tv_sec -= nsec;
        }

        /* Compute the time remaining to wait.
        tv_usec is certainly positive. */
        result->tv_sec = x->tv_sec - y->tv_sec;
        result->tv_usec = x->tv_usec - y->tv_usec;

        /* Return 1 if result is negative. */
        return x->tv_sec < y->tv_sec;
}
