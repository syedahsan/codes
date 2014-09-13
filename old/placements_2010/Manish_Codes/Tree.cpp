#include<iostream>
#include<malloc.h>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;
typedef struct tree{
	struct tree *left;
	struct tree *right;
	int val;
}tree;
typedef struct aa{
	int min;
	int max;
	int istree;
}var;
int min(int a, int b , int c){
	int min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	return min;
}
int max(int a, int b , int c){
	int max = a;
	if(max < b) max = b;
	if(max < c) max = c;
	return max;
}

tree *insert(tree *ptr, int val){
	tree *tmp1,*tmp = (tree*)malloc(sizeof(tree));
	tmp->val = val;
	tmp->left = tmp->right = NULL;
	tmp1 = ptr;
	if(!ptr) return tmp;
	while(ptr){
		if(ptr->val<val) 
		{
			if(!ptr->right){ ptr->right = tmp; break;}
			ptr = ptr->right;
		}
			
		else 
		{
			if(!ptr->left) { ptr->left = tmp; break;}
			ptr= ptr->left;
		}
	}
	return tmp1;
}
void print(tree *bst){
	if(bst){
		print(bst->left);
		printf("%d ",bst->val);
		print(bst->right);
	}
}
var verifyBST(tree *start)
{
	if(start==NULL)
	{
		var tmp;
		tmp.min = 10000;
		tmp.max = -10;
		tmp.istree =1;
		return tmp;
	}
	var tmp1 = verifyBST(start->left);
	var tmp2 = verifyBST(start->right);
	var tmp;
	tmp.min = min(start->val,tmp1.min,tmp2.min);
	tmp.max = max(start->val,tmp1.max,tmp2.max);

	if(tmp1.istree == 1 && tmp2.istree ==1 && start->val > tmp1.max && start->val < tmp2.min)
		tmp.istree = 1;
	else
		tmp.istree = 0;
	return tmp;
}
tree *treetoDouble_list(tree *ptr)
{
	if(ptr){
		tree *l,*r;
		l = treetoDouble_list(ptr->left);
		r = treetoDouble_list(ptr->right);
		ptr->left =l;
		if(r)
		{
			while(r->left) r=r->left;
			r->left=ptr;
			ptr->right = r;
		}

		if(l){ 
			l->right=ptr;
			while(ptr->right) ptr=ptr->right;
		}
		return ptr;
	}
	return NULL;
}

tree *treeto_circularDouble_list(tree *ptr)
{
	if(ptr){
		tree *l,*r;
		l = treeto_circularDouble_list(ptr->left);
		r = treeto_circularDouble_list(ptr->right);
		tree *k=ptr;
		tree *k1=ptr;
		if(r)
		{
			k1=r;
			r=r->right;
			r->left=ptr;
			ptr->right = r;
		}

		if(l){
			k=l->right;
			l->right=ptr;
			ptr->left =l;
		}
		k->left=k1;
		k1->right=k;
		return k1;
	}
	return NULL;
}
tree *tree_To_list(tree *t)
{
	if(t){
		tree *l,*r;
		l = tree_To_list(t->left);
		r = tree_To_list(t->right);
		t->left = l;
		t->right = NULL;
		if(r)
		{
			tree *tmp=r;
			while(tmp->left) tmp=tmp->left;
			tmp->left=t;
			tmp->right=NULL;
			return r;
		}
		return t;
	}
	return NULL;
}
int printDL(tree *t){
	tree *tmp = t;
	cout << t->val << " ";
	t=t->left;
	while(t!=tmp)
	{
		cout << t->val << " ";
		t=t->left;
	}
}
int height(tree *bst){
	if(bst==NULL) return 0;
	int t1 = height(bst->left);
	int t2 = height(bst->right);
return (t1>t2)?(t1+1):(t2+1);
}
void tree_mirror(tree *t){
	if(t){
	tree *tmp = t->left;
	t->left = t->right;
	t->right = tmp;
	tree_mirror(t->left);
	tree_mirror(t->right);
	}
}
tree *copy(tree *bst){
	if(!bst) return NULL;
	else{
		tree *newt = (tree*)malloc(sizeof(tree));
		newt->val = bst->val;
		newt->left = copy(bst->left);
		newt->right = copy(bst->right);
		return newt;
	}
}
int Compare(tree *t1, tree *t2){
	if(!t1 && !t2) return 1;
	else if(t1 && t2)
		return (t1->val == t2->val) && Compare(t1->left,t2->left) && Compare(t1->right,t2->right);
	else 
		return 0;
}

tree *Closest_ansestor(tree *t, int a,int b){
	if(t){
		if(t->val > a && t->val >b)
			Closest_ansestor(t->left,a,b);
		else if(t->val < a && t->val <b)
			Closest_ansestor(t->right,a,b);
		else
			return t;
	}
}
void BFS(tree *bst){
	queue<tree*> s;
	tree *tmp = bst;
	cout << "\nBFS order is ";
	while(tmp){
		cout << tmp->val << " ";
		if(tmp->left)
			s.push(tmp->left);
		if(tmp->right)
			s.push(tmp->right);
		tmp = s.front();
		s.pop();
	}
	cout << endl;
}
void DFS(tree *bst){
	stack<tree*> s;
	s.push(bst);
	tree *tmp = s.top();
	s.pop();
	cout << "DFS order is ";
	while(tmp){
		cout << tmp->val << " ";
		if(tmp->right)
			s.push(tmp->right);
		if(tmp->left)
			s.push(tmp->left);
		if(s.size()==0) break;
		tmp = s.top();
		s.pop();
	}
	cout << endl;
}
int count_leaves(tree *bst){
	if (!bst) return 0;
	else if(!bst->left && !bst->right)
		return 1;
	else 
		return count_leaves(bst->left) + count_leaves(bst->right);
}
int main(){
	int n;
	tree *bst=NULL,*New=NULL;
	cin >> n;
	while(n!=-1)
	{
		bst=insert(bst,n);
		cin >> n;
	}
//	print(bst);
/*	printf("Height = %d",height(bst));
//	print(bst);
	New = copy(bst);
	tree_mirror(bst);
//	print(New);
	BFS(bst);
	DFS(bst);
	cout << "number of leaves are: " << count_leaves(bst) << endl;
	cout << " ISBST = " << verifyBST(bst).istree << endl; 
	cout << Compare(bst,New) << endl;*/
//	bst = treetoDouble_list(bst);
	bst = treeto_circularDouble_list(bst);
	printDL(bst);
/*	int a,b;
	cin >> a >> b;
	cout << Closest_ansestor(bst,a,b)->val << endl;*/
	return 0;
}
