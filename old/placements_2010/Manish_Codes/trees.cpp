#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct tree
{
	int data;
	tree *left;
	tree *right;
}node;


queue<node*>inorder;
queue<node*>preorder;
queue<node*>postorder;
node* RecursiveInsertion(node *start , int data)
{
	if(start == NULL) 
	{     
		node *ptr = new node;
		ptr->data = data;
		ptr->left = NULL;
		ptr->right = NULL;     
		start = ptr;
	}
	else if(start->data > data)
		start->left = RecursiveInsertion(start->left,data);
	else if(start->data < data)
		start->right = RecursiveInsertion(start->right,data);
	return start;
}

void print(node *start)
{
	if(start)
	{
		preorder.push(start);            
		print(start->left);
		inorder.push(start);
		print(start->right);
		postorder.push(start);
	}
}

int distance(node *start)
{
	stack<node* > leftpreorder;
	stack<node* > rightpreorder;
	int flag = 0;
	int counter = 0;
	int leftmost = 0;
	node *ptr = start;
	while(start->left != NULL || start->right != NULL)
	{
		if(flag == 0)
			leftmost = counter;
		if(start->left)
		{
			leftpreorder.push(start);
			flag = 0;
			counter++; 
			start = start->left;          
		}
		else if(start->left == NULL)
		{
			leftpreorder.push(start);
			start = start->right;
			counter++;
			flag = 1;
		}             
	}
	flag = 0;
	counter = 0;
	int rightmost = 0;
	while(ptr->left != NULL || ptr->right != NULL)
	{
		if(flag == 0)
			rightmost = counter;
		if(ptr->right)
		{
			rightpreorder.push(ptr);
			flag = 0;
			counter++;
			ptr = ptr->right;
		}
		else if(ptr->right == NULL)
		{
			rightpreorder.push(start);
			ptr = ptr->left;
			counter++;
			flag = 1;
		}
	}
	return leftmost+rightmost+2;
}

node *LCA(node *start, int p, int q)
{
	// Not checking for non-existing nodes
	if(start == NULL) return NULL;
	if(start->left)
		if(start->left->data == p || start->left->data == q )
			return start;
	if(start->right)
		if(start->right->data == p || start->right->data == q)
			return start;
	node *left = LCA(start->left,p,q);
	node *right = LCA(start->right,p,q);
	if(left == NULL && right == NULL)
		return NULL;
	else if(left == NULL && right != NULL)
		return right;
	else if(left != NULL && right == NULL)
		return left; 
	else return start;   
}

void traverse(node *start, void fun(void))
{
	if(start == NULL) return;
	traverse(start->left,fun);
	traverse(start->right,fun);
	if(!start->left && !start->right) fun();
}

void hello()
{
	cout << "Hello World! " << endl;
}

void printer(vector<int> path, int pathlength)
{
	for(int i =0; i < pathlength; i++)
		cout << path[i] << " ";
	cout << endl;
}

void hasPath(node *start, int sum, vector<int> path, int pathlength)
{
	if(start == NULL) return;
	else
	{
		int sub = sum - start->data;
		path[pathlength] = start->data;
		pathlength++;
		cout << start->data << endl;
		if(sub == 0)
			printer(path,pathlength);
		else
		{
			hasPath(start->left,sub,path,pathlength);
			if(start->left)	
			{	sub=sub-start->left->data;
				path[pathlength] = start->left->data;
				pathlength++;
			}
			hasPath(start->right,sub,path,pathlength);
		//	sub=sub+start->data;
		}

	}
	return;
}

void callPath(node *start, int sum)
{
	vector<int> path(1000);
	queue<node*> q;
	q.push(start);
	while(q.size() > 0)
	{
		start = q.front();
		q.pop();
		if(start->data <= sum)
			hasPath(start,sum,path,0);
		if(start->left)q.push(start->left);
		if(start->right)q.push(start->right);         
	}
}

int main(void)
{
	node* start = NULL;
	int n,key;
	cout <<"Enter the numbers to be inserted" << endl;
	cin >> n;
	while(n != -1)
	{
		start = RecursiveInsertion(start,n);
		cin >> n;  
	}
	print(start);
	while(preorder.size() > 0 )
	{
		cout << preorder.front()->data << " ";
		preorder.pop();               
	}
	cout << endl;
	while(inorder.size() > 0 )
	{
		cout << inorder.front()->data << " ";
		inorder.pop();               
	}
	cout << endl;
	while(postorder.size() > 0 )
	{
		cout << postorder.front()->data << " ";
		postorder.pop();               
	}
	cout << endl;
/*	int sum;
	cin >> sum;
	callPath(start,sum);
	traverse(start,hello);*/
	int p,q;
	cin >> p;
	cin >> q;
	start = LCA(start,p,q);
	cout << "LCA is: " << start->data << endl;
	//  cout << "Max. Leftmost Distance is: " << distance(start) << endl;*/
}

