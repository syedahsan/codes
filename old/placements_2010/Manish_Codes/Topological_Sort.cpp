#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void Topological_Sort(vector< vector<int> > graph, int n)
{
	vector<int> topological(100,0);
	queue<int>tgsort;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			if(graph[j][i] !=  0)
				topological[i]++;
		if(topological[i] == 0)
			tgsort.push(i);
	}
	while(tgsort.size() > 0)
	{
		int top = tgsort.front();
		cout << top << " ";
		tgsort.pop();
		for(int j=0;j<n;j++)
			if(graph[top][j] != 0)
			{
				topological[j]--;
				if(topological[j] == 0)
					tgsort.push(j);

			}
	}         

}

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(100,vector<int>(100,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	Topological_Sort(graph,n);

}
