#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
	struct Tree *next;
}tree;

tree *insert(tree *root, int data) {

	tree *leaf = (tree *)malloc(sizeof(tree));
	leaf->data = data;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->next = NULL;

	if(root==NULL)
		return leaf;

	tree *temp=root, *prev=NULL;
	while(temp) {
		prev = temp;
		if(temp->data > leaf->data)
			temp = temp->left;
		else 
			temp = temp->right;
	}
	if(prev->data > leaf->data)
		prev->left = leaf;
	else
		prev->right = leaf;

	return root;
}
void inorder(tree *root) {

	if(!root)
		return;

	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);

	return;
}
tree * convert(tree *BST_root)
{
	tree *left = NULL;
	tree *right = NULL;
	tree *return_tree = NULL;

	if(BST_root == NULL)
		return NULL;

	if(BST_root->left)  // root of left is not empty
		left = convert(BST_root->left);

	if(BST_root->right)  // root of right is not empty
		right = convert(BST_root->right);

	BST_root->right = right;  // this is the next ptr in the Linked List
//	right->left = BST_root;
	BST_root->left = NULL;   // make this point to NULL for precaution
	return_tree = BST_root;
	if(left != NULL)
	{
		while(left->right)
		{
			left = left->right;
		}
		left->right = BST_root;
//		BST_root->left = left;
		return_tree = left;
	}
	return return_tree;
}

int main() {

	tree *root = NULL;
	int tmp;
	while(1) {
		scanf("%d",&tmp);
		if(tmp == -1)
			break;
		root = insert(root, tmp);
	}
	inorder(root);
	printf("\n");

	tree *node = convert(root);

	tree *temp = node;

	while(temp->right != node) {
		printf("%d-->", temp->data);
		temp=temp->right;
	}
	printf("NULL\n");
	
//	while(temp->left != node ) {
//		printf("%d-->", temp->data);
//		temp=temp->left;
//	}
//	printf("NULL\n");
	
	return 0;
}
