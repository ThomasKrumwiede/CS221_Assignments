#include <iostream>
#include <fstream>
//#include "graph.h"
#include "graph_With_dtfAtVertex.h"
using namespace std;

int main()
{
	Graph myGraph;

	myGraph.readGraph("..\..\CS 221\CS221_Assignment2_Part1\Problem 1 Part 2\dataG3.txt",-999);
	//myGraph.readGraph("C:\\Temp\\test.txt", -999);
	myGraph.printGraph();
	cout<<endl<<endl;
	
	cout<<"Depth First Traversal: ";
	myGraph.depthFirstTraversal();
	cout<<endl;

	cout<<"Breadth First Traversal: ";
	myGraph.breadthFirstTraversal();
	cout<<endl;
	return 0;
}