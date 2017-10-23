#include "header.cpp"
#include <fstream>
void menuWall();

int main(){
	int choice;
	hashMap dataBase; 
	int inputKey;
	int ret;
	string inputStr;
	ifstream fin;
	                    
	do{
        menuWall();
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1: // insert
            
         //             cout << "Enter entry (int) for record: ";
         //            ifstream fin;
                     fin.open("dict.txt");
                    
                     while (!fin.eof()){
                     	getline(fin,inputStr,'\n');	
                      	dataBase.insert(inputStr);
//                      	cout<<inputStr<<endl;
                     } 
                      fin.close();
                      cout << "Record was inserted in table" << endl << endl;
                      break;
                      
            case 2: // search
                    	cout<<"Enter String to Search: "<<endl;
              /*
              		 fin.open("dict.txt");
                	 while (!fin.eof()){
                	 	getline(fin,inputStr,'\n');                	                                                                      
               */                     
               		 	cin >> inputStr;
                      	ret = dataBase.search(inputStr);
                      	if (ret==-1){
                      		cout<<"ERROR:404. Not Found!!"<<endl;
                      		cout<<inputStr;
                      		break;
                      	}
//                     }	
                     	 else
                      		cout<<"Key value is: "<< ret <<endl;	

                      break;          

            case 10: cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }//switch
    }//do.
    while ( choice!=0 );
}

void menuWall(){
    cout << endl;
    cout << "The following choices are available: " << endl;
    cout << " 1   Insert a new record or update existing record" << endl;
    cout << " 2   Find a record" << endl;
    cout << " 0   Quit this test program" << endl << endl;
}
