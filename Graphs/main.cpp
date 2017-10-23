#include "header.cpp"



void menuWall();

int main(){

	vector<tempEdge> vecE;
	int choice; int srcInd, destInd;
	string readStr, inputStr;
	ifstream fin;
	string m_name, from, to;
	double m_weight;
	int  m_x, m_y;
	double filter=0; 
	choice=1;
	
	while (choice!=0){
		
		menuWall();
		cout<< "Enter Choice: ";
		cin>>choice;

	switch (choice){

		case 1: //data input file.	
			cout<< "Enter the valid name of the InputFile: ";
			cin.ignore();
			cin >> inputStr;
			fin.open(inputStr.c_str());  
			break;

		case 2: // Kruskal's method/...	

			while (!fin.eof()){
				getline(fin,readStr,'\n');
				istringstream ss(readStr);
				ss >> m_name;
		
				if ( m_name=="ARCS"){
					filter=1;
				}
				if ( m_name=="NODES"){
					continue;
				}
				else if( filter==1 || m_name=="ARCS"){
					if (m_name=="ARCS")
						continue;
					else{ // Put your Edges here....
						from = m_name;
						ss >> to >> m_weight;
						tempEdge newTempEdge;
						newTempEdge.source = from;
						newTempEdge.dest = to;
						newTempEdge.weight = m_weight;  
						vecE.push_back(newTempEdge);
					}//else.	
		
				}
				else if (filter==0){ // getVertices from here....
					ss>> m_x >> m_y;
					vertex newV;
					newV.name = m_name;
					newV.x = m_x;
					newV.y = m_y;
					vecV.push_back(newV);
				}//else if...
	
	
			}//while.

			Graph* graph = createGraph(vecV.size(), vecE.size());

			// This would create your graph where vertex would map to cetain indices....!!!!

			for (int i=0; i<vecE.size(); i++){
				for (int j=0; j<vecV.size(); j++){
					if (vecV[j].name==vecE[i].source){
						srcInd = j;
						break;
					}
				}
				for (int j=0; j<vecV.size(); j++){
					if (vecV[j].name ==vecE[i].dest){
						destInd = j;
						break;
					}
				}
				graph->edge[i].source = srcInd;
				graph->edge[i].dest = destInd;
				graph->edge[i].weight = vecE[i].weight;	
			}
			kruskals_method(graph);	
			break;
//		case 10: 
//			cout<< "Programe would terminate Now!"<<endl;
//		default: cout<<choice <<" is invalid."<<endl;
	}// switch.
	if (choice==2){
		break;
	}
	}
	//	while (choice!=0);	 		
// References: GeekforGeeks. Like to detect a cycle, I have used Union method;
// And in class we have not read about it at all.			
/* // ........Display the vector.......
	vector<tempEdge>::iterator itS=vecE.begin(), itE=vecE.end();

	while (itS!=itE){
		cout<< itS->source <<" "<< itS->dest << endl;
		itS++;
	}
*/
}//main..

	void menuWall(){
		cout<<endl;
    	cout<< "_1: Choose DataFile. "<<endl;
    	cout<< "_2: Find MST using Kruskal's Algorithm. "<<endl;
    	cout<< "_0: Quit. "<<endl;
	}    
