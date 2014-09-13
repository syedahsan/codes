#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
using namespace std;

int main(void)
{
	int n;
	int flag =0;
	cin >> n;
	int graph[n][n];
	vector<int> d(n,INT_MAX);
	vector<int> predessor(n,-1);
	stack<int> path;
	queue<int> vertex;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	d[0] = 0;
	vertex.push(0);
	while(vertex.size() > 0)
	{
		int i = vertex.front();
		vertex.pop();
		for(int j=0;j<n;j++)
		{
			if(graph[i][j] != 0)
			{
				if(d[j] > d[i] + graph[i][j])
				{
					d[j] = d[i] + graph[i][j];
					predessor[j] = i;
					vertex.push(j);
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(graph[i][j] !=0)
			{
				if(d[j] > d[i] + graph[i][j])
				{
					flag = 1;
					break;
				}
			}
	if(flag == 1) cout << "Cycle Exists" << endl;
	else
	{
		int destinationvertex;
		cin >> destinationvertex;
		while(destinationvertex != -1)
		{
			path.push(destinationvertex);
			destinationvertex = predessor[destinationvertex];
		}
		while(path.size() > 0)
		{
			cout << path.top() << " ";
			path.pop();
		}
		cout << endl;
	}
}
