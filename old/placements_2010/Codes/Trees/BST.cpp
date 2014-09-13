#include <iostream>
#include <queue>
#include <cmath>
#include "BST.h"

using namespace std;

void 
BinarySearchTree::insert(int val) {

	treenode *leaf = new treenode();
	leaf->data = val;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->colour = 0;
	leaf->start = -1;
	leaf->finish = -1;

	if(root == NULL) {
		root = leaf;
		return;
	}
	
	treenode *temp = root;
	treenode *prev = NULL;

	while(temp) {

		prev = temp;
		if(temp->data > leaf->data)
			temp = temp->left;
		else if(temp->data <= leaf->data)
			temp = temp->right;

	}

	if(prev->data > leaf->data)
		prev->left = leaf;
	else
		prev->right = leaf;

	return;
}
void BinarySearchTree::print(treenode *sth, int pos) {

	if(!sth)
		return;
	print(sth->right,pos+1);
	for(int i=0; i<pos; i++)
		cout << "\t";
	cout << sth->data << endl;
	print(sth->left,pos+1);

	return;
}
void
BinarySearchTree::print() {
	print(root,0);
}
void
BinarySearchTree::inorder(treenode *sth) {

	if(!sth)
		return;
	
	inorder(sth->left);
	cout << sth->data << endl;
	inorder(sth->right);

	return;
}
void
BinarySearchTree::postorder(treenode *sth) {

	if(!sth)
		return;
	
	postorder(sth->left);
	postorder(sth->right);
	cout << sth->data << endl;

	return;
}
void
BinarySearchTree::preorder(treenode *sth) {

	if(!sth)
		return;
	
	cout << sth->data << endl;
	preorder(sth->left);
	preorder(sth->right);

	return;
}
void
BinarySearchTree::inorder() {
	inorder(root);
	return;
}
void
BinarySearchTree::postorder() {
	postorder(root);
	return;
}
void
BinarySearchTree::preorder() {
	preorder(root);
	return;
}
int BinarySearchTree::depth(treenode *sth) {
	if(!sth)
		return 0;
	else 
		return (1 + max(depth(sth->left), depth(sth->right)));
}
int BinarySearchTree::depth() {
	depth(root);
}
void BinarySearchTree::allorder(treenode *sth, queue<int> &pre, queue<int> &in, queue<int> &post) {
	if(!sth)
		return;
	pre.push(sth->data);
	allorder(sth->left, pre, in, post);
	in.push(sth->data);
	allorder(sth->right, pre, in, post);
	post.push(sth->data);

	return;
}
void BinarySearchTree::allorder() {
	queue<int> pre, in, post;
	allorder(root, pre, in, post);
	
	cout << "Preorder :" << endl;
	while(!pre.empty()) {
		cout << pre.front() << " ";
		pre.pop();
	}
	cout << endl;

	cout << "Inorder :" << endl;
	while(!in.empty()) {
		cout << in.front() << " ";
		in.pop();
	}
	cout << endl;

	cout << "Postorder :" << endl;
	while(!post.empty()) {
		cout << post.front() << " ";
		post.pop();
	}
	cout << endl;
}
void BinarySearchTree::levelorder() {

	if(!root) 
		return;

	queue<treenode *> Q;

	treenode *delem = new treenode();
	delem->left = NULL;
	delem->right = NULL;
	delem->data = INT_MAX;

	Q.push(root);
	Q.push(delem);

	while(!Q.empty()) {
		treenode *temp = Q.front();
		Q.pop();
		if(temp->data==INT_MAX) {
			cout << endl;
			if(!Q.empty())
				Q.push(delem);
			continue;
		}
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
		cout << temp->data << " ";
	}
}

void BinarySearchTree::BFS() {
	levelorder();
}
int BinarySearchTree::treeDFS(treenode *sth, int time) {

	if(!sth) 
		return 0;

	sth->colour = 1;
	time++;
	sth->start = time;

	if(sth->left) 
		if( sth->left->colour == 0 )
			time = treeDFS(sth->left, time);
	if(sth->right)
		if( sth->right->colour == 0 )
			time = treeDFS(sth->right, time);

	sth->colour = 2;
	time++;
	sth->finish = time;
	cout << "Node[" << sth->data << "]  \t" << sth->start << "\t" << sth->finish << endl;
	return time;
}
void BinarySearchTree::DFS() {
	int time = treeDFS(root,0);
}

