#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
	int data;
	struct BinaryTree *left, *right;
}tree;

int max(int a, int b) {
	return ((a>b)?a:b);
}
tree *allocate(int val) {
	tree *temp = (tree*)malloc(sizeof(tree));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
}

void print(tree *toprint, int pos) {

	int i;
	if(!toprint)
		return;
	print(toprint->right,pos+1);
	for(i=0; i<pos; i++)
		printf("\t");
	printf("%d\n", toprint->data);
	print(toprint->left, pos+1);

	return;
}

int isBST(tree *tocheck) {

	int FLAG=1;

	if(!tocheck)
		return 1;
	if(tocheck->left) 
		FLAG = ((tocheck->data > tocheck->left->data) && isBST(tocheck->left));
	if(tocheck->right) 
		FLAG = FLAG && ((tocheck->data <= tocheck->right->data) && isBST(tocheck->right));

	return FLAG;
}

void iterativepreorder(tree *root) {

	if(!root)
		return;

	int top=0;
	tree *arr[100];
//	arr = (arr**)malloc(100*sizeof(arr*));

	arr[top++] = root;
	while(top) {
		tree *temp = arr[--top];
		if(temp->right)
			arr[top++] = temp->right;
		if(temp->left)
			arr[top++] = temp->left;
		printf("%d ", temp->data);
	}
	printf("\n");

	return;
}
void inorder(tree *root) {

	if(!root)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

/*tree *construct_pre_in(int pre[], int in[], int N) {


}*/

void copy_mirror(tree **new, const tree *root) {

	if(!root)
		return;
	*new = allocate(root->data);
	copy_mirror(&((*new)->right), root->left);
	copy_mirror(&((*new)->left), root->right);

	return;
}

int isISOMORPHIC(tree *first, tree *second) {

	if(!first && !second)
		return 1;
	if( (first && !second) || (!first && second) )
		return 0;

	if(first && second)
		return ( (isISOMORPHIC(first->left, second->left) && isISOMORPHIC(first->right, second->right)) || (isISOMORPHIC(first->left, second->right) && isISOMORPHIC(first->right, second->left)) );
}

/*tree *LCA(tree *root, int a, int b) {
	


}*/


int height(tree *node) {

	if(!node)
		return 0;
	int lh = height(node->left);
	int rh = height(node->right);

	return (1 + max(lh,rh));
}
int diameter(tree *node) {

	if(!node)
		return 0;

	int lh = height(node->left);
	int rh = height(node->right);

	return max(1+lh+rh, max(diameter(node->left), diameter(node->right)) );
}
int main() {
	
	tree *root=NULL,*root1=NULL;

	// Creating Binary Tree manually
	root = allocate(4);
	root->left = allocate(6);
	root->right = allocate(8);
	root->left->left = allocate(3);
	root->left->right = allocate(2);
	root->right->left = allocate(7);
	root->right->right = allocate(9);

	root1 = allocate(10);
	root1->left = allocate(6);
	root1->right = allocate(14);
	root1->left->left = allocate(4);
	root1->left->right = allocate(8);
	root1->right->left = allocate(12);
	root1->right->right = allocate(16);
	root1->right->right->right = allocate(18);

	print(root,0);
	printf("\n");
	print(root1,0);
	printf("\n");

	printf("IS BST ?\n");
	printf("%d\n",isBST(root));
	printf("%d\n",isBST(root1));

	printf("PREORDER\n");
	iterativepreorder(root);

	printf("INORDER\n");
	inorder(root);
	printf("\n");

/*
	int i, N, pre[100], in[100];
	scanf("%d",&N);
	for(i=0; i<N; i++)
		scanf("%d", &pre[i]);
	for(i=0; i<N; i++)
		scanf("%d", &in[i]);


	tree *new = construct_pre_in(pre, in, N);
	print(new);
	printf("\n");
*/	

	tree *mirror = NULL;
	copy_mirror(&mirror, root1);
	print(mirror,0);
	printf("\n");
	print(root1,0);
	printf("\n");

	printf("IS ISOMORPHIC ?\n");
	printf("%d\n",isISOMORPHIC(root1,mirror));

/*
	tree *ancestor = LCA(root, 12, 18);
	if(ancestor)
		printf("%d\n", ancestor->data);
	else
		printf("NULL\n");
*/
	int dia = diameter(root1->right);
	printf("Diameter %d\n", dia);



}
