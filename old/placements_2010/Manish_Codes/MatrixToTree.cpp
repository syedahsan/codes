#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;

typedef struct tree
{
	tree *left;
	tree *right;
	int data;
}node;
int n;
vector< vector<int> > matrix(100, vector<int>(100,0));

node** TreeVector = (node**)malloc(sizeof(node*)*100);
vector<int> Ancestors()
{
	vector<int> AncestorsCount(n,0);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(matrix[i][j] != 0) AncestorsCount[i]++;
	return AncestorsCount;
}

vector<int> ConstructTree(vector<int> AncestorsCount)
{
	int parent = 0;
	for(int i=0;i<n;i++)
	{
		if(AncestorsCount[i] == 1)
		{
			for(int j=0;j<n;j++)
			{
				if(matrix[i][j] !=0)
				{
					parent = j;
					break;
				}
			}
			node *start = TreeVector[parent];
			node *p = new node;
			p->left = NULL;
			p->right = NULL;
			p->data = i;
			if(start->left == NULL) start->left = p;
	        	else if(start->right == NULL) start->right = p;
			TreeVector[i]=p;
		}	
	}
	for(int i=0;i<n;i++){ matrix[i][parent]=0; AncestorsCount[i]--;}
	return AncestorsCount;

}

void print(node *start)
{
	if(start == NULL) return;
	print(start->left);
	cout << start->data << " ";
	print(start->right);
}

int main(void)
{
	int root;
	cout << "Size of Matrix" << endl;
	cin >> n;
	vector<int> AncestorsCount(n,0);
	for(int i=0;i<n;i++)
	     for(int j=0;j<n;j++)
	         cin >> matrix[i][j];
	AncestorsCount= Ancestors();
	for(int i=0;i<n;i++)
	  if(AncestorsCount[i] == 0)
	     root = i;
	node *start = new node;
	start->left = NULL;
	start->right = NULL;
	start->data = root;
	TreeVector[root]=start;
	while(1)
	{
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if(AncestorsCount[i] <= 0)
				count++;
		}
		cout << count << endl;
		if(count == n)
			break;
		else
			AncestorsCount = ConstructTree(AncestorsCount);
	}
	print(TreeVector[root]);
}
