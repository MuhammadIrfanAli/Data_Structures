#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// I could not temlatize each and every struct and function because I am running out of time.....
// Since time is limited, I am trying to focus more on Kruskal's rather than Trivial problems like 
// temlatizing. I believe assigment to be open ended, so my method might seem non-customary to you..
// But it worsk fine.....


struct vertex{
	string name;
	int x;
	int y;
};

struct Edge{
	int source;
	int dest;
	double weight;

};

struct tempEdge{
	string source;
	string dest;
	double weight;
};


struct Graph{
	int numV;
	int numE;
	struct Edge* edge;

};

struct subset{
	int parent;
	int rank;

};


void menuWall();
//struct Graph* createGraph(int numV, int numE);
//void kruskals_method(struct Graph* graph);
