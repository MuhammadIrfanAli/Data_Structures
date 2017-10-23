#include "header.h"
#include <stdio.h>


vector<vertex> vecV;
// Path Compression Technique....

int find(struct subset subsets[], int i){

	if (subsets[i].parent!=i){
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;

}
//<------------------------------------------------------------------->
// Comparison function.....

int compare(const void* temp, const void* temp2){
	struct Edge* trav1 = (struct Edge*)temp;
	struct Edge* trav2 = (struct Edge*)temp2;
	return trav1->weight > trav2->weight;

}// Compare
//<------------------------------------------------------------------->
// Merge 
int merge(struct subset subsets[], int first, int second){
	int firstRoot = find(subsets,first);
	int secondRoot = find(subsets,second);
    if (subsets[firstRoot].rank < subsets[secondRoot].rank)
        subsets[firstRoot].parent = secondRoot;
    else if (subsets[firstRoot].rank > subsets[secondRoot].rank)
        subsets[secondRoot].parent = firstRoot;

    else
    {
        subsets[secondRoot].parent = firstRoot;
        subsets[firstRoot].rank++;
    }
}


//<------------------------------------------------------------------->
struct Graph* createGraph(int numV, int numE){ // Allocation for Graph....

	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->numV = numV;
    graph->numE = numE;
 
    graph->edge = (struct Edge*) malloc( graph->numE * sizeof( struct Edge ) );
 
    return graph;

}// graph*.....
//<------------------------------------------------------------------->
// the main function comes into being here,......

void kruskals_method(struct Graph* graph){
	int i=0, e=0;
	int Vertices = graph->numV;
	struct Edge result[Vertices];
	qsort(graph->edge, graph->numE, sizeof(graph->edge[0]), compare);
		
	//memory for creating subsets
    struct subset *subsets = (struct subset*) malloc( Vertices * sizeof(struct subset) );
 
 
    for (int k = 0; k < Vertices; k++)
    {
        subsets[k].parent = k;
        subsets[k].rank = 0;
    }
 
    // We know number of edges in MST equal to |V-1|.
    while (e < Vertices - 1)
    {

        struct Edge next_edge = graph->edge[i++];
 
        int first = find(subsets, next_edge.source);
        int second = find(subsets, next_edge.dest);

        if (first != second)
        {
            result[e++] = next_edge;
            merge(subsets, first, second);
        }
    }		

	cout << "Required Minimum Spanning Tree is: " <<endl;
    for (i = 0; i < e; ++i){
        int srcInd = result[i].source; 
        int destInd = result[i].dest; 
        cout<< vecV[srcInd].name<<" -> "<< vecV[destInd].name<<" with weight: "<< result[i].weight <<endl;
    }    
    return;	

}// Kruskals....
//<------------------------------------------------------------------->
void dijkstra_method(){




}



