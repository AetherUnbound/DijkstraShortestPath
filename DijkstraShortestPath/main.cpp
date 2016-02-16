//Implementation of Dijkstra's Shortest Path Greedy Algorithm
//Matthew Bowden

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include "node.h"


void dijkstra(int[V][V], int);
int minDistance(int[], bool[]);
int printSolution(int[], int, Node[]);
int numReverse(int);
string strReverse(string);


int main()
{   
	//run the dijkstra algorithm for each vertex of the graph given
	for (int i = 0; i < V; i++){
		dijkstra(graph, i);
	}
    return 0;
}


//Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
//This code has been copied and motified from "Geeks for Geeks" (http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/)
void dijkstra(int graph[V][V], int startingVertex) {	
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[startingVertex] = 0;

	 //Initialize NodeArray with length equal to number of vertices
	 Node NodeArray[V];

	 //First node will have its parent be itself
	 //This is used as a break condition later on
	 NodeArray[startingVertex] = Node(startingVertex, startingVertex);

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
			 //Add a new node to the NodeArray under the current vertex
			 //Assign parent as vertex determined to have shortest path from visited vertices
			 NodeArray[v] = Node(v, u);
			 dist[v] = dist[u] + graph[u][v];
		 }
			
     }
 
     // print the constructed distance array
     printSolution(dist, startingVertex, NodeArray);
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   //Finds the minimum distance value
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n, Node array[])
{   
   
   cout << "\nVertex   Distance from Source: " << n << endl;
   for (int i = 0; i < V; i++) {
	   bool flag = false;
	   cout << i << "\t\t" << dist[i];

	   //For the current vertex, use the parent nodes of each node to 
	   //  trace back path to source node
	   Node curr = array[i];
	   string output = "";
	   output += to_string(curr.nodeNum);
	   while (!flag) {		
		   //Check to see if current node is source node
		   if (curr.nodeNum == curr.parent) {
			   flag = true;
		   }
		   else {
			    //Add (reverse) string to the array
			    //Just realized this will not work for graphs with more than 9 nodes...
				output += ">--" + to_string(numReverse(curr.parent));
				curr = array[curr.parent];
		   }		   
	   }
	   //print string backwards
	   cout << "\tPath: ";
	   output = strReverse(output);
	   cout << output << endl;
   }
   return 0;
}

int numReverse(int src) {
	if (src > 9) {
		string temp = to_string(src);
		temp = strReverse(temp);
		src = stoi(temp);
	}
	return src;
}

string strReverse(string src) {\
	string temp = "";
	for (int x = src.length()-1; x >=0; x--)
		temp += src[x];
	return temp;
}