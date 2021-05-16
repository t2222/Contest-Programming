#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring> // needed for memsets
#include<cstdio>
#include <cmath>
#include<stack>
#include<utility> // needed for pair
#include<queue>
#include<set>
#include<map>
#include<set>
#include<numeric> // used accumulate
#include <bitset>

#define MAX 1000

using namespace std;

typedef long long int lld;
typedef long double llf;
typedef unsigned long long int ulld;

using namespace std;

class Graph
{
	int v;
	int e;
	int** adj;
public:
	Graph(int v);
	~Graph();
	void printGraph();
	void addEdge(int start, int end);
	void bfs(int start);
	void dfs(int start);
	void dijkstra(int start, int end);
};

Graph::Graph(int v) // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
{
	this->v = v; // adj matrix will be vXv
	adj = new int* [v];// allocate memory for cols which is a 1d array of pointers
	for (int i = 0; i < v; i++)
	{
		adj[i] = new int[v]; // populate cols with 1d rows
		for (int j = 0; j < v; j++) // initialize with data
		{
			adj[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	for (int i = 0; i < v; i++)
	{
		delete[] adj[i]; // delete each rows, but the array of pointers that make up each column remain 
	}
	delete[] adj;
}

void Graph::printGraph()
{
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
}

void Graph::addEdge(int start, int end)
{
	adj[start][end] = 1;
	adj[end][start] = 1;
}

/*
BFS():
create a queue Q
mark v as visited and put v into Q
while Q is non-empty
	remove the head u of Q
	mark and enqueue all (unvisited) neighbours of u
*/
void Graph::bfs(int start)
{
	vector<int> quu;
	vector<bool> visited(v, false);
	quu.push_back(start);
	visited[start] = true;
	while (!quu.empty()) // while q not empty
	{
		int visited_vertex = quu[0];
		cout << visited_vertex << " ";
		quu.erase(quu.begin());
		for (int i = 0; i < v; i++)
		{
			if (adj[i][visited_vertex] == 1 && !visited[i])
			{
				quu.push_back(i);
				visited[i] = true;
			}
		}
	}
}

void Graph::dfs(int start) // there might be different results possible for dfs and bfs traversal, just using stack instead of queue gets us the dfs
{
	stack<int> stk;
	vector<bool> visited(v, false);
	stk.push(start);
	visited[start] = true;
	while (!stk.empty())
	{
		int visited_vertex = stk.top();
		stk.pop();
		cout << visited_vertex << " ";
		for (int i = 0; i < v; i++)
		{
			if (adj[i][visited_vertex] == 1 && !visited[i])
			{
				stk.push(i);
				visited[i] = true;
			}
		}
	}
}



int main()
{
	/*
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 9);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(9, 3);
	g.dfs(2);
	cout << endl;
	Graph dg(5);
	dg.addEdge(0, 1);
	dg.addEdge(0, 2);
	dg.addEdge(0, 3);
	dg.addEdge(1, 2);
	dg.addEdge(2, 4);
	dg.addEdge(3, 3);
	dg.addEdge(4, 4);

	dg.bfs(0);
	*/

	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 4);
	g.bfs(0);
	cout << "\n";
	g.dfs(0); // there might be different results possible for dfs and bfs traversal, just using stack instead of queue gets us the dfs
}
