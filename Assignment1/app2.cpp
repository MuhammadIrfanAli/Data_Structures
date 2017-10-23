#ifndef __APP2_CPP
#define APP2_CPP
#include "stack.cpp"
#include <iostream>
using namespace std;

int Find_F_N(int n){

	Stack<int> seq;
	int sum=0;
	int ret=0;
	int prepreSum, preSum;
	if (n==0){
		seq.push(n);
		ret = seq.pop();
		return ret;
	}//if.
	
	else{
		for (int i=1; i<=n; i++){
			if (i==1){
				prepreSum=0;
				preSum=1;
			}
			else{
				sum = preSum + prepreSum;
				seq.push(sum);
				prepreSum = preSum;
				preSum=sum;
			}	
		}//for.
		ret = seq.pop();
		return ret;
	}//else.	

}//fibonacci..
int main(){

	int num;
	int res=0;
	cout<<"enter the number upto which you intend to find fibonacci seq!!"<<endl;
	cin>>num;
	res = Find_F_N(num);
	cout<<" F("<<num<<") is: "<<res<<endl;
	return 0;

}
#endif
