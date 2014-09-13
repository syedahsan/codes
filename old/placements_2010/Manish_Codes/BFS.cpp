#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;

vector<int>dist(100,0);
int flag[100];
int parent[100];

void BFS(vector< vector<int> > graph,int v,int e,int vertex)
{
	for(int i=0;i<v;i++)
	{
		flag[i] = 0;
		parent[i] = -1;
		dist[i] = INT_MAX;

	}
	flag[vertex] = 1;
	parent[vertex] = -1;
	dist[vertex]= 0;
	queue<int>bfs;
	bfs.push(vertex);
	while(bfs.size() > 0)
	{
		int vertex = bfs.front();
		bfs.pop();
		for(int i=0;i<e;i++)
		{
			if(graph[vertex][i] == 1 && flag[i] == 0)
			{
				flag[i] = 1;
				parent[i] = vertex;
				dist[i] = dist[vertex] + 1;
				bfs.push(i);
			}
		}
		flag[vertex] = 2;
	}
}

void Print_Path(vector< vector<int> > graph, int s, int v)
{
	 if(v== s) cout << "";
	 else if(parent[v] == -1) cout << "No path from s to v exists" << endl;
	 else Print_Path(graph,s,parent[v]);
	 cout << v << " ";
}

int main(void)
{
	int v,e;
	vector< vector<int> > graph(100,vector<int>(100,0));
	cin >> v >> e;
	for(int i =0;i<v;i++)
		for(int j =0;j<e;j++)
			cin >> graph[i][j];
	int vertex;
	cin >> vertex;
	BFS(graph,v,e,vertex);
	int end;
	cin >> end;
	Print_Path(graph,vertex,end);
	//for(int i=0;i<v;i++)
	//	cout << flag[i] << " " << parent[i] << " " << dist[i] << endl;
}

