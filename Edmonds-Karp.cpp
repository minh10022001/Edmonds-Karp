#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

#define MAXN 99 // maximum number of nodes in graph
#define INF INT_MAX

/* Examples for to test program
Ex1:
INPUT:
7 11 0 6
0 1 3
0 3 3
1 2 4
2 0 3
2 3 1
2 4 2
3 4 2
3 5 6
4 1 1
4 6 1
5 6 9
OUTPUT: 5

Ex2:
INPUT:
6 10 0 5
0 1 16
0 2 13
1 2 4
1 3 12
2 1 10
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
OUTPUT: 23
*/

// represents the capacities of the edges
int capacity[MAXN][MAXN];
// shows how much flow has passed through an edge
int flowPassed[MAXN][MAXN];
// represents the graph and it may contain negative edges (residual network)
vector <int> graph[MAXN];
// show the path builed by BFS in grarph
int parList[MAXN];
// shows the maximum flow to a node in the path built by the BFS
int currentPathC[10];
// show  a node which is visited  or not
bool visited[10];


// Find path builed by BFS and path flow in residual network

int bfs(int sNode, int eNode){
	
	memset(parList, -2, sizeof(parList));
	memset(visited, false, sizeof(visited));
	memset(currentPathC, 0, sizeof(currentPathC));
	queue<int> q; //declar queue
	q.push(sNode);
	visited[sNode]  = true; // sNode is visited
	parList[sNode] = -1; // initialize parlist's source node
	currentPathC[sNode] = INF;//initialize currentpath's source node
   
	while(!q.empty()){
		int currNode = q.front();
		q.pop();
		for(int i = 0; i<graph[currNode].size(); i++){
			int to  = graph[currNode][i];
			if(visited[to] == false){
				if(capacity[currNode][to] - flowPassed[currNode][to] > 0){
					visited[to] = true;
					parList[to] = currNode;
					currentPathC[to] =  min(currentPathC[currNode],
										capacity[currNode][to] - flowPassed[currNode][to]);
					if(to == eNode){
						return currentPathC[eNode];
					}
					q.push(to);
				}
			}
		}	
		
   }
   return 0;
}

// Edmonds-Karp 

int edmondsKarp(int sNode, int eNode){
	int maxFlow = 0; // There is no flow initially
	while(true){
		int pathFlow = bfs(sNode, eNode);
		if(pathFlow == 0){
			break;//not exists path flow build by BFS in residual network
		}
		
		// Add path flow to overall flow
		maxFlow += pathFlow;
		// update residual capacities of the edges and reverse edges along the path
		int currNode = eNode;
		while(currNode != sNode)
		{	
			int prevNode = parList[currNode];
				flowPassed[prevNode][currNode] += pathFlow;
				flowPassed[currNode][prevNode] -= pathFlow;
				currNode = prevNode;
		}
	
		
		
	}
	return maxFlow;
}

int main(){
	int numberNode, numberEdge;
	cout<<"Enter the number of nodes and edges: \n";
	cin>>numberNode>>numberEdge;
	
	int start, target;
	cout<<"Enter the startNode and tagetNode: \n";
	cin>>start>>target;
	
	cout<<"Enter the start and end vertex along with capacity for each edge\n";
	for(int e = 0; e< numberEdge; e++){
		int from,to,cap;
		cin>>from>>to>>cap;
		capacity[from][to] = cap;
		graph[from].push_back(to);
		graph[to].push_back(from);
		
	}
	int maxFlow = edmondsKarp(start, target);
	cout<<"Max flow : "<<maxFlow<<endl;
	
}

