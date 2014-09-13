#include<iostream>
#include<queue>
#include<vector>
#include<malloc.h>
using namespace std;

typedef struct nn
{
	int data;
	nn * right;
	nn *left;
	nn *next;
}node;
queue<node*> Stack;
vector< vector<int> > matrix(100,vector<int>(100,0));


node *insert(node *start, vector<int> array)
{
	queue<node*> binary;
	binary.push(start);
	node *temp = start;
	for(int i =1;i<array.size();i+=2)
	{
		if(array[i] != 0)
		{
			node *l = new node;
			l->data = array[i];
			l->left = NULL;
			l->right = NULL;
			binary.push(l);
			start = binary.front();
			start->left = l;
		}
		if(array[i+1] !=0)
		{
			node *r = new node;
			r->data = array[i+1];
			r->left = NULL;
			r->right = NULL;
			binary.push(r);
			start = binary.front();
			start->right = r;
		}
		binary.pop();
	}
	return temp;    

}


node* linkinsert(node *start, int n)
{
	node *p = new node;
	p->data = n;
	p->next = NULL;
	if(start == NULL)
		start = p;
	else
	{
		node *temp = start;
		while(temp->next)
			temp = temp->next;
		temp->next = p;
	}
	return start;
}

void print(node *start)
{
	while(start)
	{
		cout << start->data << " ";
		start = start->next;
	}
}

void preorder(node *start)
{
	if(start != NULL)
	{
		Stack.push(start);
		preorder(start->left);
		preorder(start->right);
	}
}

void ConstructMatrix()
{
	node** array = (node**) malloc(sizeof(node*)*100);
	int i=0;
	while(Stack.size() > 0)
	{
		node *start = Stack.front();
		Stack.pop();
		array[i] = linkinsert(NULL,start->data);
		if(start->left) array[i] = linkinsert(array[i],start->left->data);
		if(start->right) array[i] = linkinsert(array[i],start->right->data);
		i++;
	}
	for(int j=0;j<i;j++)
	{
		int x,y;
		node *start = array[j];
		x = start->data;
		start = start->next;
		while(start)
		{
			y = start->data;
			node *temp = array[y-1];
			while(temp != NULL)
			{
				matrix[x][temp->data] = 1;
				temp = temp->next;
			}
			start = start->next;
		}
	}
	for(int j=1;j<=i;j++)
	{
		for(int k=1;k<=i;k++)
			cout << matrix[j][k] << " ";
		cout << endl;
	}

}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
        for(int i =0;i< n;i++)
	    cin >> a[i];
	node *start = new node;
	start->data = a[0];
	start->left = NULL;
	start->right = NULL;
	start = insert(start,a);
	preorder(start);
	ConstructMatrix();
}
