#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

int main(){
    string tempStr;
 //   vector <string> vec;
    ifstream fin;
    fin.open("input.txt");
    int i=0;

    while (!fin.eof() && i<100){
        getline(fin,tempStr);
        char_separator<char> sep("\");
        tokenizer<char_separator<char>> tokens(tempStr, sep);
        for (const auto& t : tokens) {
            cout << t << "." << endl;
        }
        /*
        istringstream iss(tempStr);
        while ( getline(iss, tempStr,'\ ') )
            vec.push_back(tempStr);
            cout<<tempStr<<endl;

        */
    i++;
    }//while.
}
