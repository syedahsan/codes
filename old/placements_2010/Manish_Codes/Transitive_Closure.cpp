#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > Transitive_Closure(vector< vector<int> > graph, vector< vector<int> > transitive, int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i == j || graph[i][j] != 0)
				transitive[i][j] = 1;
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				transitive[i][j] = transitive[i][j] || (transitive[i][k] && transitive[k][j]);
	return transitive;
}

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	vector< vector<int> > transitive(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	transitive = Transitive_Closure(graph,transitive,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << transitive[i][j] << " ";
		cout << endl;
	}
}
