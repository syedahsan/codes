#include<iostream>
#include<vector>
using namespace std;

vector<int>flag(100,0);
vector<int> finish(100,0);
vector<int>discovery(100,0);
int t;

void DFS_Visit(vector< vector<int> > graph, int n, int i)
{
	flag[i] = 1;
	t = t +1;
	discovery[i] = t;
	for(int j=0;j<n;j++)
		if(graph[i][j] != 0 && flag[j] == 0)
			DFS_Visit(graph,n,j);
	flag[i] = 2;
	finish[i] = t;
	t+=1;
}

void Topological_Sort(vector< vector<int> > graph, int n)
{
	t=0;
	for(int i=0;i<n;i++)
		if(flag[i] == 0)
		{
			flag[i] == 1;        
			DFS_Visit(graph,n,i);
		}
}

int Path_Num(vector< vector<int> > graph, int n, int p, int q)
{
	int path_num = 0;
	if(finish[p] < finish[q])
		return 0;
	for(int i=0;i<n;i++)
	{
		if(graph[p][i] != 0)
		{
			if(i == q) path_num+=1;
			else path_num+=Path_Num(graph,n,i,q);            
		}  
	}
	return path_num;
}

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(100,vector<int>(100,0));
	for(int i=0;i<n;i++)
		for(int j =0;j<n;j++)
			cin >> graph[i][j];
	int p,q;
	cin >> p >> q;
	cout << Path_Num(graph,n,p,q) << endl;
}
