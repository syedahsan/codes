#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	vector<int> distance(n,INT_MAX);
	vector<int> predessor(n,-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	distance[0] = 0;
	multimap<int,int> heap;
	for(int i=0;i<n;i++)
		heap.insert(pair<int,int>(distance[i],i));
	while(heap.size() > 0)
	{
		int vertex = heap.begin()->second;
		heap.erase(heap.begin());
		for(int j=0;j<n;j++)
			if(graph[vertex][j] != 0)
				if(distance[j] > distance[vertex] + graph[vertex][j])
				{
					heap.erase(distance[j]);
					distance[j] = distance[vertex] + graph[vertex][j];
					predessor[j] = vertex;
					heap.insert(pair<int,int>(distance[j],j));
				}
	}
	for(int i=0;i<n;i++)
		cout << distance[i] << " "  << predessor[i] << endl;
}
