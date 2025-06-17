#ifndef H_GRAPH
#define H_GRAPH

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <list>
using namespace std;
const int MAX_SIZE = 20;

class Graph
{
public:
	//default constructor
	//Postcondition: The graph size is set to 0, that is,
	//               gSize = 0; maxSize = size.
	Graph();

	//destructor
	//Postcondition: The storage occupied by the graph 
	//               is deallocated.
	~Graph();

	//Function to determine whether the graph is empty.
	//Postcondition: Returns true if the graph is empty; 
	//               otherwise, returns false.
    bool isEmpty();
    
	//Function to create the graph reading from a file and using  
	//the adjacency list representation.
	//Postcondition: The graph is created in the form of
	//               adjacenty lists.
    //void createGraph();
	virtual void readGraph(string fileName, int sentinel);
	
    //Function to deallocate the memory occupied by the linked 
	//lists and the array of pointers pointing to the linked
	//lists.
    void clearGraph();
    
	//Function to print the graph.
    void printGraph();
      
	//Function to perform the depth first traversal of
	//the entire graph.
    void depthFirstTraversal();
    
	//Function to perform the depth first traversal of 
	//the graph at a node specified by the parameter vertex.
    void dftAtVertex_(int vertex);
      
	//Function to perform the breadth first traversal of
	//the entire graph.
    void breadthFirstTraversal();
      
	//Function to retrieve the vertices adjacent to a given 
	//vertex.
	//Postcondition: The vertices adjacent to a given vertex 
	//               are retrieved in the array adjacencyList. 
	//               The parameter vIndex specifies the vertex 
	//               index in the array graph
	//               The parameter length specifies the number 
	//               of vertices adjacent to a given vertex.
	void getAdjacentVertices(int vIndex, int adjacencyList[], 
                                                 int& length);
	
	//Function to return the size of the graph (number of vertices)
	int getSize();

protected:
    int maxSize;         //maximum number of vertices
    int gSize;           //current number of vertices
    list<int> graph[MAX_SIZE]; //array of adjacency lists

private:
	//Helper function to perform the depth first traversal 
	//of the graph starting at a particular node.
    void dft(int v, bool visited[]);
       
};

#endif