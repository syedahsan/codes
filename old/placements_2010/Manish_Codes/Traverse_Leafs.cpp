#include<iostream>
#include<queue>
using namespace std;

typedef struct tree
{
	tree *left;
	tree *right;
	int data;
}node;

node *insert(node *start, int n)
{
	if(start == NULL)
	{
		node *p = new node;
		p->left = NULL;
		p->right = NULL;
		p->data =n;
		start = p;
		return start;
	}
	if(start->data > n)
		start->left = insert(start->left,n);
	else start->right = insert(start->right,n);
	return start;

}

void inorder(node *start)
{
	if(start == NULL) return;
	inorder(start->left);
	cout << start->data << endl;
	inorder(start->right);
}

void BFS(node *start)
{
	queue<node*> bfs;
	bfs.push(start);
	while(bfs.size() > 0)
	{
		node* top = bfs.front();
		bfs.pop();
		if(top->left) bfs.push(top->left);
		if(top->right) bfs.push(top->right);
		if(top->left == NULL && top->right == NULL)
			cout << top->data << " ";
	}
}

int main(void)
{
	node *start = NULL;
	int n;
	cin >> n;
	while(n != -1)
	{
		start = insert(start,n);
		cin >> n;
	}
	BFS(start);
	cout << endl;
}
