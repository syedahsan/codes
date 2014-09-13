#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;

int heap_size = 0;
vector<int>whoTo(100,0);

typedef struct heap_node
{
	int distance;
	int i;
	int j;
}heap_node;

void Insert_Heap(heap_node *heap, int distance, int i, int j)
{
	++heap_size;
	heap[heap_size].distance = distance;
	heap[heap_size].i = i;
	heap[heap_size].j = j;
	int size = heap_size;
	while(size > 1 && heap[size].distance < heap[size/2].distance)
	{
		swap(heap[size],heap[size/2]);
		size=size/2;
	}

}

void Min_Heapify(heap_node *heap, int i)
{
	int smallest;
	int lChild = 2*i;
	int rChild = 2*i+1;
	if(lChild <= heap_size && heap[lChild].distance < heap[i].distance)
		smallest = lChild;
	else smallest = i;
	if(rChild <= heap_size && heap[rChild].distance < heap[smallest].distance)
		smallest = rChild;
	if(i != smallest)
	{
		swap(heap[i],heap[smallest]);
		Min_Heapify(heap,smallest);
	}

}

heap_node* ExtractMin(heap_node *heap)
{
	heap_node *start = (heap_node*) malloc(sizeof(heap_node)*1);
	start[0] = heap[1];
	swap(heap[1],heap[heap_size]);
	--heap_size;`
	Min_Heapify(heap,1);
	return start;
}

void Decrease_Key(heap_node *heap, int distance, int i, int j)
{
	for(int k = 1;k<=heap_size;k++)
		if(heap[k].i == j)
		{
			if(distance < heap[k].distance)
			{
				whoTo[j] = i;
				heap[k].distance = distance;
				while(k > 1 && heap[k].distance < heap[k/2].distance)
				{
					swap(heap[k],heap[k/2]);
					k=k/2;
				}
			}
		}
}

int main(void)
{
	heap_node *heap = (heap_node*)malloc(sizeof(heap_node)*100);
	heap_node *start = (heap_node*)malloc(sizeof(heap_node)*1);
	int n;
	cin >> n;
	vector< vector<int> > graph(n,vector<int>(n,0));
	vector< vector<int> > Spanning_Tree(n,vector<int>(n,0));
	vector<int> distance(n,100000);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	heap[0].distance = -32456;
	heap[0].i=32456;
	heap[0].j=32456;
	distance[0] = 0;
	for(int i=0;i<n;i++)
		Insert_Heap(heap,distance[i],i,i);
	start = ExtractMin(heap);
	while(heap_size > 0)
	{
		int i = start[0].i;
		for(int j=0;j<n;j++)
		{
			if(graph[i][j] != 0)
			{
				Decrease_Key(heap,graph[i][j],i,j);
				graph[j][i] = 0;
			}
		}
		start = ExtractMin(heap);
		Spanning_Tree[whoTo[start[0].i]][start[0].j] = start[0].distance;
	}
	cout << endl << "Minimum Spanning Tree" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << Spanning_Tree[i][j] << " ";
		cout << endl;
	}
}
