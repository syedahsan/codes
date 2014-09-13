#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

#define SIZE 100000
#define NUM_CHILD 10
    
typedef struct _tree {
    int data;
    struct _tree *child[NUM_CHILD];
    struct _tree *parent;
} tree;

void print(tree *root)
{
        _print(root, 0);
}

tree *allocate(int val)
{
    tree *node = new tree();
    node->data = val;
    for (int i = 0; i < NUM_CHILD; ++i)
            node->child[i] = NULL;
    node->parent = NULL;
    
    return (node);
}

tree* _create_tree(tree *node, int idx, int a[], int n)
{
    node = allocate(idx);
    for (int i = idx+1, int j = 0; i < n; ++i) {
        if (a[i] == idx) {
            node->child[j] = _create_tree(node->child[j], i, a, n);
            node->child[j]->parent = node;
            ++j;
        } else {
                break; /* make sure whether we need this statement */
        }
    }
    
    return (node);
}            

tree* create_tree(int a[], int n)
{
    tree *root = NULL;
    root = _create_tree(root, 0, a, n);
    return (root);
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[SIZE];
    int b[SIZE];
    int N;
    int i;
    int M;
   
    a[0] = -1;
    scanf("%d", &N);
    for (i = 1; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &M);
    for (i = 0; i < M; ++i) {
            scanf("%d", &b[i]);
    
    tree* root = create_tree(a, N);

    return 0;
}
