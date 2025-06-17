/*  Problem1.cpp
	Thomas Krumwiede
	12/2/24
	The main funciton and test prograrm for required for Assignment 2 problem 1*/
#include <iostream>
#include <fstream>
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
	//myGraph.depthFirstTraversal();
	cout<<endl;
	cout << "Total Cost: " << myGraph.depthFirstTraversal() << endl;

	//test the breadth first traversal 
	cout<<"Breadth First Traversal: ";
	//myGraph.breadthFirstTraversal();
	cout<<endl;
	cout << "Total Cost: " << myGraph.breadthFirstTraversal() << endl;

	//test dftAtVertex() for ever vertex in the graph 
	cout << "dftAtVertex 0: ";
	cout << "Total Cost " << myGraph.dftAtVertex_(0);
	cout << endl;

	cout << "dftAtVertex 1: ";
	cout << "Total Cost " << myGraph.dftAtVertex_(1);
	cout << endl;

	cout << "dftAtVertex 2: ";
	cout << "Total Cost " << myGraph.dftAtVertex_(2);
	cout << endl;

	cout << "dftAtVertex 3: ";
	cout << "Total Cost " << myGraph.dftAtVertex_(3);
	cout << endl;

	cout << "dftAtVertex 4: ";
	cout << "Total Cost " << myGraph.dftAtVertex_(4);
	cout << endl;


	return 0;
}