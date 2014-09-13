#include<iostream>
#include<vector>
using namespace std;

vector<int>parent(100,0);
vector<int>flag(100,0);
vector<int>discovery(100,0);
vector<int>finish(100,0);
int t;

void DFS_Visit(vector< vector<int> > graph, int n, int i)
{
	t+=1;
	discovery[i] = t;
	flag[i] = 1;
	for(int j=0;j<n;j++)
		if(graph[i][j] != 0 && flag[j] == 0)
		{
			parent[j] = i;
			DFS_Visit(graph,n,j);            
		}
	flag[i] = 2;    
	finish[i] = t+1;
	t+=1;
}

void DFS(vector< vector<int> > graph, int n)
{
	t=0;
	for(int i=0;i<n;i++)
		if(flag[i] == 0)
			DFS_Visit(graph,n,i);
}

int main()
{
	int n;
	cin >> n;
	vector< vector<int> > graph(100,vector<int>(100,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	DFS(graph,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]!=0)
			{     
				if(discovery[i] < discovery[j] && discovery[j] < finish[j] && finish[j] < finish[i])
					cout << "Tree Edge: " << i << " " << "to " << j << endl;
				if(discovery[j] <= discovery[i] && discovery[i] <= finish[i] && finish[i] <= finish[j])
					cout << "Back Edge: " << i << " " << "to " << j << endl;
				if(discovery[j] < finish[j] && finish[j] < discovery[i] && discovery[i] < finish[i])
					cout << "Cross Edge: " << i << " " << "to " << j << endl;
			}
		}
	}
}

