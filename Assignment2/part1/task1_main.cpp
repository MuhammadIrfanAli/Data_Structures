#include "time.h"
#include "header.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(){

	startTimer();
	tree<string> dirTree;

	ifstream fin;
	fin.open("input.txt");
	string tempStr, s1,s2;
	vector <string> dirVec;	
	while (!fin.eof()){
		int d;
		getline(fin, tempStr);
		istringstream iss(tempStr);
		while ( getline(iss,tempStr,'\\'))
			dirVec.push_back(tempStr);

		// Now Insert the elem in the vector in the Tree of N Children.
		for ( int i=0; i<dirVec.size()-1; i++ ){
			s1 = dirVec[i];
			s2 = dirVec[i+1];
			
			int d = dirTree.insert(s2,s1);
				if (d==0){
					dirTree.insert(s2,s1);
				}
				else{
					continue;	
				}
		}//for.	
		
	}//while.
	stopTimer();
}

