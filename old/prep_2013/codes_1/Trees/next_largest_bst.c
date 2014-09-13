/* same code as next inorder */

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
        int data;
        struct _tree *left;
        struct _tree *right;
        struct _tree *parent;
} tree;

tree *allocate(int val)
{
        tree *node = calloc(1, sizeof(tree));
        node->data = val;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        return (node);
}

/* BST insert */
tree *insert(tree *root, int val)
{
        if (root == NULL) {
                tree *node = allocate(val);
                return (node);
        }

        if (val <= root->data) {
                root->left = insert(root->left, val);
                root->left->parent = root;
        } else {
                root->right = insert(root->right, val);
                root->right->parent = root;
        }

        return (root);
}

void _print(tree *node, int hd)
{
        if (node == NULL)
                return;

        int i;
        _print(node->right, hd+1);
        for (i = 0; i < hd; ++i)
                printf("\t");
        printf("%d\n", node->data);
        _print(node->left, hd+1);
}

void print(tree *root)
{
        _print(root, 0);
}

/* THIS IS THE TARGET FUNCTION */
/* next largest node */
tree *next_inorder(tree *node)
{
        if (node == NULL)
                return (NULL);

        if (node->right) {
                node = node->right;
                while (node && node->left)
                        node = node->left;
        } else {
                while (node) {
                        tree *ptr = node;
                        node = node->parent;
                        if (node && node->left == ptr)
                                break;
                }
        }

        return (node);
}

void inorder(tree *root)
{
        if (root == NULL)
                return;

        /* reach the leftmost node */
        while (root && root->left)
                root = root->left;

        while (root) {
                printf("%d ", root->data);
                root = next_inorder(root);
        }
        printf("\n");

        return;
}

int main()
{
        int n;
        tree *root = NULL;

        while (1) {
                scanf("%d", &n);
                if (n == -1)
                        break;

                root = insert(root, n);
        }

        print(root);

        inorder(root);

        return 0;
}
