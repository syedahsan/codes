#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

#define SIZE 50
    
typedef struct _tree {
    int data;
    struct _tree *left;
    struct _tree *right;
} tree;

tree *allocate(int val)
{
    tree *node = new tree();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    
    return (node);
}

tree* _create_tree(tree *node, queue<int>& Q, int a[], int n)
{
    if (Q.empty())
        return (NULL);
    
    int idx = Q.front();
    node = allocate(idx);
    Q.pop();

    int i;
    for (i = 0; i < n; ++i) {
        if (a[i] == idx) {
            Q.push(i);
            node->left = _create_tree(node->left, Q, a, n);
            break;
        }
    }
    for (i++; i < n; ++i) {
        if (a[i] == idx) {
            Q.push(i);
            node->right = _create_tree(node->right, Q, a, n);
            break;
        }
    }
    
    return (node);
}            

tree* create_tree(int a[], int n)
{
    tree *root = NULL;
    queue<int> Q;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            Q.push(i);
            break;
        }
    }
    
    root = _create_tree(root, Q, a, n);
    return (root);
}    

void print_reverse_level_order(tree *root)
{
        if (root == NULL)
                return;

        queue<tree *> Q;
        stack<int> S;
        int sC = 1;
        int sN = 0;

        Q.push(root);

        while (!Q.empty()) {
                tree *node = Q.front();
                Q.pop();
                --sC;

                if (node) {
                        S.push(node->data);
                        Q.push(node->right);
                        Q.push(node->left);
                        sN += 2;
                }

                if (sC == 0) {
                        S.push(-1);
                        sC = sN;
                        sN = 0;
                }
        }

        while (!S.empty()) {
                int val = S.top();
                S.pop();
                if (val == -1)
                        printf("\n");
                else
                        printf("%d ", val);
        }
        printf("\n");
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[SIZE];
    int N;
    int i;
    
    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    
    tree* root = create_tree(a, N);
    print_reverse_level_order(root);
        
    return 0;
}
