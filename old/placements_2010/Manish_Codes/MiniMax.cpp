#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > MinMax(vector< vector<int> > graph, int n)
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int maximum = max(graph[i][k],graph[k][j]);
				graph[i][j] = min(graph[i][j],maximum);
			}
	return graph;
}

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	/*for (int i=0;i<n;i++)
		  graph[i][i] = 0;*/
	graph = MinMax(graph,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}
