#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <queue>

using namespace std;

class BinarySearchTree {

	private:
		typedef struct TreeNode {
			int data;
			struct TreeNode *left;
			struct TreeNode *right;

			// TO BE USED DURING DFS
			int colour, start, finish;
			/* Colour = 0, 1 and 2 */
		}treenode;

		treenode *root;
		void inorder(treenode *);
		void postorder(treenode *);
		void preorder(treenode *);
		int depth(treenode *);
		void allorder(treenode *,queue<int>&,queue<int>&,queue<int>&);
		void print(treenode *, int);
		int treeDFS(treenode *, int);

	public:
		BinarySearchTree() {
			root = NULL;
		}
		void insert( int );
		void print();
		int depth();
		void inorder();
		void postorder();
		void preorder();
		void allorder();
		void levelorder();
		void DFS();
		void BFS();

};

#endif
