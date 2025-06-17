/*  graph_With_dftAtVertex.cpp
    Thomas Krumwiede
    12/2/24
    The graph implementation required for Assignment 2 problem 1*/
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
     double cost;

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
             infile >> cost;
			 graph[vertex].emplace_back(adjacentVertex, cost);
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
		list<pair<int, double>>::iterator pos;
		for (pos = graph[index].begin(); pos != graph[index].end(); pos++)
			cout << pos->first << " " << pos->second << " ";
		cout<<endl;
	 }
	 cout << endl;
}//end printGraph

double Graph::depthFirstTraversal()
{
     bool *visited;    //array to keep track of the visited
                       //vertices
     visited = new bool[gSize];

     double totalCost = 0.0;

     for(int index = 0; index < gSize; index++) 
         visited[index] = false;   
 
     for(int index = 0; index < gSize; index++) //for each vertex
         if(!visited[index])          //that is not visited,
             totalCost += dft(index,visited);      //do a depth first
                                     //traversal
     delete [] visited;
     return totalCost;
}//end depthFirstTraversal

double Graph::dft(int v, bool visited[])
{
     list<pair<int, double>> adjacencyList;
     int alLength = 0;  //the number of adjacent vertices

     double cost = 0.0;

     visited[v] = true;
     cout << " " << v << " ";  //process the vertex

	 //retrieve the adjacent vertices into adjacencyList                  
	 getAdjacentVertices(v, adjacencyList, alLength);

	 for(list<pair<int, double>>::const_iterator iter = adjacencyList.begin(); iter != adjacencyList.end(); ++iter) //for each 
     {                                  //vertex adjacent to v
         int adjacent = iter->first;
         double edgeCost = iter->second;

         //add cost to total cost 
         //totalCost += edgeCost;

         if (!visited[adjacent])
             cost += edgeCost + dft(adjacent, visited); //recursion
     }
     
     return cost;
}//end dft

double Graph::dftAtVertex_(int vertex)
{
    //create a bool variable used to determine if a node had been visited 
     bool *visited;

     visited = new bool[gSize];

     double totalCost = 0;
     //initailize all nodes in the graph as unvisited 
     for(int index = 0; index < gSize; index++)
         visited[index] = false;
       
     //initiate dft() member fuinction at a specified node 
     totalCost += dft(vertex,visited);
    
     //Check for any nodes that were not visited durring the original dft() call 
     //for (int index = 0; index < gSize; index++)
        //if(visited[index] == false)  dft(index, visited);


     delete [] visited;
     return totalCost;
} //end dftAtVertex



double Graph::breadthFirstTraversal()
{
   queue<int> q;
   int u;

   bool *visited;
   visited = new bool[gSize];

   for(int ind = 0; ind < gSize; ind++)
       visited[ind] = false;    //initialy no vertex is visited                                 

   list<pair<int, double>> adjacencyList;
   int alLength = 0;
   double totalCost = 0;

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
             
             for (const auto& edge : adjacencyList) {
                 int adjacent = edge.first;
                 double edgeCost = edge.second;

                 if (!visited[adjacent])
                 {
                     totalCost += edgeCost;
                     q.push(adjacent);
                     visited[adjacent] = true;

                     cout << " " << adjacent << " ";
                 } //end if
             }
         } //end while
      } //end if
 
   delete [] visited;
   //delete [] adjacencyList;
   return totalCost;
} //end breadthFirstTraversal


void Graph::getAdjacentVertices(int vIndex, list<pair<int, double>> &adjacencyList, int& length)
{
    adjacencyList = graph[vIndex];

    adjacencyList.sort([](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second < b.second; // Compare by the second element (double)
        });

} //end getAdjacentVertices


int Graph::getSize()
{
	return gSize;
}
