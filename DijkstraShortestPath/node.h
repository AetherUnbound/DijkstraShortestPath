#ifndef HEADER_H
#define HEADER_H

// Number of vertices in the graph
#define V 9

using namespace std;

//Globals and prototypes
int graph[V][V] = {{ 0,  4,  0,  0,  0,  0,  0,  8,  0},
                   { 4,  0,  8,  0,  0,  0,  0, 11,  0},
                   { 0,  8,  0,  7,  0,  4,  0,  0,  2},
                   { 0,  0,  7,  0,  9, 14,  0,  0,  0},
                   { 0,  0,  0,  9,  0, 10,  0,  0,  0},
                   { 0,  0,  4, 14, 10,  0,  2,  0,  0},
                   { 0,  0,  0,  0,  0,  2,  0,  1,  6},
                   { 8, 11,  0,  0,  0,  0,  1,  0,  7},
                   { 0,  0,  2,  0,  0,  0,  6,  7,  0}
                  };

//Data structure to hold current node and parent node
struct Node {	
	int nodeNum;
	int parent;
	Node ();
	Node (int, int);
};

//Default Constructor
Node::Node() {
	nodeNum = -1;
	parent = 0;
}

//Constructor with values
Node::Node(int num, int par) {
	nodeNum = num;
	parent = par;
}

#endif