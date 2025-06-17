/*  graph_With_dftAtVertex.cpp
    Thomas Krumwiede
    12/3/24
    The implmentation of graph required for problem 1a in assignment 2*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <list>
#include "graph_With_dtfAtVertex.h"
using namespace std;

//default constructor
Graph::Graph()
{
	maxSize = MAX_SIZE;
	gSize = 0;
}

//destructor
Graph::~Graph()
{
	clearGraph();
}

bool Graph::isEmpty()
{
	return (gSize == 0);
}

void Graph::readGraph(string fileName, int sentinel)
{
     ifstream infile; 

     int vertex;
     int adjacentVertex;

     if(gSize != 0)  //if the graph is not empty, make it empty
        clearGraph();	

	 infile.open(fileName.c_str(), ios::in);
	 
     if(!infile)
     {
        cerr<<"Cannot open the input file."<< fileName << endl;
        return;
     }

     infile >> gSize;  //read the number of vertices
	 
     for(int index = 0; index < gSize; index++)
     {
         infile>>vertex;
         infile>>adjacentVertex;

         //while(adjacentVertex != -999)
		 while (adjacentVertex != sentinel)
         {
			 graph[vertex].push_back(adjacentVertex);
             infile>>adjacentVertex;			
		 }//end while
     }//end for

     infile.close();
}//end readGraph

void Graph::clearGraph()
{
     int index;

     for(index = 0; index < gSize; index++)
         graph[index].clear();

     gSize = 0;
}

void Graph::printGraph()
{
	 cout << "Graph size " << gSize << endl<< endl;
     for(int index = 0; index < gSize; index++)
	 {   
		cout <<"Vertex " << index<<": ";
		list<int>::iterator pos;
		for (pos = graph[index].begin(); pos != graph[index].end(); pos++)
			cout << *pos << " ";		
		cout<<endl;
	 }
	 cout << endl;
}//end printGraph

void Graph::depthFirstTraversal()
{
     bool *visited;    //array to keep track of the visited
                       //vertices
     visited = new bool[gSize];

     for(int index = 0; index < gSize; index++) 
         visited[index] = false;   
 
     for(int index = 0; index < gSize; index++) //for each vertex
         if(!visited[index])          //that is not visited,
             dft(index,visited);      //do a depth first
                                     //traversal
     delete [] visited;
}//end depthFirstTraversal

void Graph::dft(int v, bool visited[])
{
     int *adjacencyList;     //array to retrieve the
                           //adjacent vertices
     adjacencyList = new int[gSize];
 
     int alLength = 0;  //the number of adjacent vertices

     visited[v] = true;
     cout << " " << v << " ";  //process the vertex

	 //retrieve the adjacent vertices into adjacencyList                  
	 getAdjacentVertices(v, adjacencyList, alLength);
     
	 for(int index = 0; index < alLength; index++) //for each 
     {                                  //vertex adjacent to v
		 int adjacent = adjacencyList[index];
         if(!visited[adjacent])
            dft(adjacent, visited); //recursion
     }//end for

     delete [] adjacencyList;
}//end dft

void Graph::dftAtVertex_(int vertex)
{
    //create a bool variable used to determine if a node had been visited 
     bool *visited;

     visited = new bool[gSize];

     //initailize all nodes in the graph as unvisited 
     for(int index = 0; index < gSize; index++)
         visited[index] = false;
       
     //initiate dft() member fuinction at a specified node 
     dft(vertex,visited);
    
     //Check for any nodes that were not visited durring the original dft() call 
     for (int index = 0; index < gSize; index++)
         if(visited[index] == false)  dft(index, visited);


     delete [] visited;
} //end dftAtVertex



void Graph::breadthFirstTraversal()
{
   queue<int> q;
   int u;

   bool *visited;
   visited = new bool[gSize];

   for(int ind = 0; ind < gSize; ind++)
       visited[ind] = false;    //initialy no vertex is visited                                 

   int *adjacencyList;
   adjacencyList = new int[gSize];

   int alLength = 0;

   for(int index = 0; index < gSize; index++)
      if(!visited[index])
      {
         q.push(index);
         visited[index] = true;
         cout << " " << index << " ";

		 while (q.size() > 0)
         {
			 u = q.front();             
			 q.pop();
             getAdjacentVertices(u, adjacencyList, alLength);
             
			 for(int w = 0; w < alLength; w++)
                 if(!visited[adjacencyList[w]])
                 {              
					q.push(adjacencyList[w]);
                    visited[adjacencyList[w]] = true;
                    cout<< " " << adjacencyList[w] << " ";
                 } //end if
         } //end while
      } //end if
 
   delete [] visited;
   delete [] adjacencyList;
} //end breadthFirstTraversal

void Graph::getAdjacentVertices(int vIndex, int adjacencyList[], int& length)
{
	list<int>::iterator pos;
	length = 0;
	for (pos = graph[vIndex].begin(); pos != graph[vIndex].end(); pos++)
		adjacencyList[length++] = *pos;
} //end getAdjacentVertices

int Graph::getSize()
{
	return gSize;
}
