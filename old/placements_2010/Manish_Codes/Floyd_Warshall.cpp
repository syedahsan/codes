#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n = 5;
vector< vector<int> > graph(n,vector<int>(n,0));
vector< vector<int> > predessor(n,vector<int>(n,-1));
void Floyd_Warshall()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
					predessor[i][j] = predessor[k][j];
				}
			}
		}
	}
}

void Print(int i, int j)
{
	if(i == j) cout << i << " ";
	else if(predessor[i][j] == -1) cout << "No Path Exists" << endl;
	else 
	{
		Print(i,predessor[i][j]);
		cout << j << " ";
	}
}

int main(void)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(graph[i][j] != 0 && graph[i][j] != 34567)
				predessor[i][j] = i; 
	Floyd_Warshall();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << predessor[i][j] << " ";
		cout << endl;
	}
	int destination;
	cin >> destination;
	Print(0,destination);
	cout << endl;
}
