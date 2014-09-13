/*5
0 3 8 34567 -4
34567 0 34567 1 7
34567 4 0 34567 34567
2 34567 -5 0 34567
34567 34567 34567 6 0*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector< vector<int> > predessor(100,vector<int>(100,-1));

vector< vector<int> > Extend_Shortest_Path(vector< vector<int> > graph, int n)
{
	vector< vector<int> > newgraph(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			newgraph[i][j] = INT_MAX;
			for(int k=0;k<n;k++)
			{
				if(newgraph[i][j] > graph[i][k] + graph[k][j])
				{
					newgraph[i][j] = graph[i][k] + graph[k][j];
					predessor[i][j] = predessor[k][j];
				}
			}
		}
	}
	return newgraph;
}

vector < vector<int> > ComputeMatrix(vector< vector<int> > graph, int n)
{
	int m = 1;
	while(m < n-1)
	{
		graph = Extend_Shortest_Path(graph,n);
		m = 2*m;
	}
	return graph;
}

void Print(int i, int j)
{
	if(i == j) cout << i << " ";
	else if(predessor[i][j] == -1)
	{
		cout << "No Path Exists" << endl;
	}
	else
	{
		Print(i,predessor[i][j]);
		cout << j << " ";
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		cin >> graph[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(graph[i][j] != 0 && graph[i][j] != 34567)
				predessor[i][j] = i;
	graph = ComputeMatrix(graph,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << predessor[i][j] << " ";
		cout << endl;
	}
	int destination;
	cin >> destination;
	Print(0,destination);
}
