/*9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/


#include<iostream>
#include<vector>
#include<malloc.h>
#include<algorithm>
using namespace std;

int heap_size = 0;
typedef struct Heap_node
{
	int weight;
	int i;
	int j;
}heap_node;

void Insert_Heap(heap_node *heap, int i, int j, int value)
{
	++heap_size;
	heap[heap_size].weight = value;
	heap[heap_size].i = i;
	heap[heap_size].j = j;
	int size = heap_size;
	while(size > 1 && heap[size].weight < heap[size/2].weight)
	{
		swap(heap[size],heap[size/2]);
		size = size/2;
	}

}

void Min_Heapify(heap_node *heap, int i)
{
	int smallest;
	int lChild = 2*i;
	int rChild = 2*i + 1;
	if(lChild <= heap_size && heap[lChild].weight < heap[i].weight)
		smallest = lChild;
	else
		smallest = i;
	if(rChild <= heap_size && heap[rChild].weight < heap[smallest].weight)
		smallest = rChild;
	if(i != smallest)
	{
		swap(heap[smallest],heap[i]);
		Min_Heapify(heap,smallest);
	}
}

heap_node* deleteMin(heap_node *heap)
{
	heap_node *start = (heap_node*) malloc(sizeof(start)*1); 
	start[0] = heap[1];
	swap(heap[1],heap[heap_size]);
	--heap_size;
	Min_Heapify(heap,1);
	return start;
}


int main(void)
{
	heap_node *heap = (heap_node*) malloc(sizeof(heap)*100);
	 heap_node *start = (heap_node*) malloc(sizeof(start)*1);
	heap[heap_size].weight = -32567;
	heap[heap_size].i = -32567;
	heap[heap_size].j = -32567;
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(graph[i][j] != 0)
			{
				Insert_Heap(heap,i,j,graph[i][j]);
				graph[j][i] = 0;
			}
		}
	int size = heap_size;
	vector< vector<int> > Spanning_Tree(n,vector<int>(n,0));
	vector<int> flag(n,0);
	int flagvalue = 1;
	while(size > 0)
	{
		start = deleteMin(heap);
		if(flag[start[0].i] == 0 && flag[start[0].j] == 0)
		{
			Spanning_Tree[start[0].i][start[0].j] = start[0].weight;
			flag[start[0].i] = flagvalue;
			flag[start[0].j] = flagvalue;
			flagvalue++;
			size--;
		}
		else if(flag[start[0].i] == 0 && flag[start[0].j] != 0)
		{
			Spanning_Tree[start[0].i][start[0].j] = start[0].weight;
			flag[start[0].i] = flag[start[0].j];
			size--;
		}
		else if(flag[start[0].i] != 0 && flag[start[0].j] == 0)
		{
			Spanning_Tree[start[0].i][start[0].j] = start[0].weight;
			flag[start[0].j] = flag[start[0].i];
			size--;
		}
		else if(flag[start[0].i] !=0 && flag[start[0].j] != 0 && flag[start[0].i] != flag[start[0].j])
		{
			Spanning_Tree[start[0].i][start[0].j] = start[0].weight;
			int minimum = min(flag[start[0].i],flag[start[0].j]);
			int maximum = max(flag[start[0].i],flag[start[0].j]);
			for(int k=0;k<n;k++)
				if(flag[k] == minimum)
					flag[k] = maximum;
			size--;
		}
		else if(flag[start[0].i] !=0 && flag[start[0].j] != 0 && flag[start[0].i] == flag[start[0].j])
		{
			size--;
			continue;
		}
	}
	cout << endl << endl << "Minimum Spanning Tree is" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << Spanning_Tree[i][j] << " ";
		cout << endl;
	}
}

