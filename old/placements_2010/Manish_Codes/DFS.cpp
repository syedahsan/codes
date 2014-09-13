#include<iostream>
#include<vector>

using namespace std;

int t;
vector<int>d(100,0);
vector<int>f(100,0);
vector<int>parent(100,-1);
vector<int> flag(100,0);

void DFS_Visit(vector< vector<int> > graph, int v, int e, int vertex)
{
	flag[vertex] = 1;
	t = t+1;
	d[vertex] = t;
	for(int i=0;i<e;i++)
	{
		if(graph[vertex][i] == 1 && flag[i] == 0)
		{
			parent[i] = vertex;
			DFS_Visit(graph,v,e,i);
		}
	}
	flag[vertex] = 2;
	f[vertex] = t+1;
	t++;
}	

void DFS(vector< vector<int> > graph, int v, int e)
{
	t=0;
	for(int i=0;i<v;i++)
	{
		if(flag[i] == 0)
			DFS_Visit(graph,v,e,i);
	}
}



int main(void)
{
	int v,e;
	cin >> v >> e;
	vector< vector<int> > graph(100,vector<int>(100,0));
	for(int i=0;i<v;i++)
	   for(int j =0;j<e;j++)
		   cin >> graph[i][j];
	DFS(graph,v,e);
	for(int i =0;i<v;i++)
		cout << parent[i] << " " << f[i] << " " << d[i] << endl;
}
