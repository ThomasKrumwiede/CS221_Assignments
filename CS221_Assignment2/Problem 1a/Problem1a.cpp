/*  Problem1a.cpp
	Thomas Krumwiede
	12/3/24
	The main function and test program required for problem 1a in assignment 2*/
#include <iostream>
#include <fstream>
//#include "graph.h"
#include "graph_With_dtfAtVertex.h"
using namespace std;

int main()
{
	//create graph and read verticies from the .txt file 
	Graph myGraph;

	myGraph.readGraph("C:\\Temp\\test.txt",-999);
	//myGraph.readGraph("C:\\Temp\\test.txt", -999);
	myGraph.printGraph();
	cout<<endl<<endl;
	
	//test the depth first traversal 
	cout<<"Depth First Traversal: ";
	myGraph.depthFirstTraversal();
	cout<<endl;

	//test the breadth first traversal 
	cout<<"Breadth First Traversal: ";
	myGraph.breadthFirstTraversal();
	cout<<endl;

	//test dftAtVertex() for ever vertex in the graph 
	cout << "dftAtVertex 0: ";
	myGraph.dftAtVertex_(0);
	cout << endl;

	cout << "dftAtVertex 1: ";
	myGraph.dftAtVertex_(1);
	cout << endl;

	cout << "dftAtVertex 2: ";
	myGraph.dftAtVertex_(2);
	cout << endl;

	cout << "dftAtVertex 3: ";
	myGraph.dftAtVertex_(3);
	cout << endl;

	cout << "dftAtVertex 4: ";
	myGraph.dftAtVertex_(4);
	cout << endl;


	return 0;
}