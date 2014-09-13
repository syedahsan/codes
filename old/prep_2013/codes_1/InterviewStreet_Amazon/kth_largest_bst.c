#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
        int data;
        struct _tree *left;
        struct _tree *right;
} tree;

tree* allocate(int val)
{
        tree *node = calloc(1, sizeof(tree));
        node->data = val;
        node->left = NULL;
        node->right = NULL;

        return (node);
}

/* iterative insert */
tree* insert_BST_iterative(tree *root, int val)
{
        tree *temp = allocate(val);

        if (root == NULL)
                return (temp);

        tree *it = root;
        tree *p_it = NULL;
        while (it) {
                p_it = it;
                if (val >= it->data)
                        it = it->right;
                else
                        it = it->left;
        }

        if (val >= p_it->data)
                p_it->right = temp;
        else
                p_it->left = temp;

        return (root);
}

/* recursive insert */
tree* insert_BST_recursive(tree *root, int val)
{
        if (root == NULL)
                return (allocate(val));

        if (val >= root->data) {
                root->right = insert_BST_recursive(root->right, val);
        } else {
                root->left = insert_BST_recursive(root->left, val);
        }

        return (root);
}

void _print(tree *root, int spc)
{
        if (root == NULL)
                return;

        int i;

        _print(root->right, spc + 1);
        for (i = 0; i < spc; i++)
                printf("\t");
        printf("%d\n", root->data);
        _print(root->left, spc + 1);

        return;
}

void print_awesome(tree *root)
{
        _print(root, 0);
}

void _cleanup(tree *root)
{
        if (root == NULL)
                return;

        _cleanup(root->left);
        root->left = NULL;

        _cleanup(root->right);
        root->right = NULL;
        
        if (root->left == NULL && root->right == NULL) {
                free(root);
                return;
        }
}


void cleanup(tree **root)
{
        _cleanup(*root);
        *root = NULL;
}

int tree_size(tree *root)
{
        if (root == NULL)
                return (0);
        else
                return (1 + tree_size(root->left) + tree_size(root->right));
}

int kth_smallest(tree *root, int* k)
{
        if (!root || (k && *k < 0))
                return (-1);
        int rl = kth_smallest(root->left, k);
        *k = *k - 1;
        if (*k == 0) {
                return (root->data);
        }
        int rr = kth_smallest(root->right, k);
        return ((rl > rr) ? rl : rr);
}

int kth_largest(tree *root, int k)
{
        if (root == NULL || k < 0)
                return (-1);

        int size = tree_size(root);
        if (k > size)
                return (-1);

        int nk = size - k;
        return (kth_smallest(root, &nk));
}

int main()
{
        int n;
        tree *root = NULL;

        while (1) {
                scanf("%d", &n);
                if (n == -1)
                        break;
                root = insert_BST_iterative(root, n);
        }

        print_awesome(root);
        printf("\n\n");

        int k;
        scanf("%d", &k);

        printf("Kth (%d) Largest Element: %d\n", k, kth_largest(root, k));

        cleanup(&root);
        return 0;
}

