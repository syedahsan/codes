#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
        int data;
        struct _tree *left;
        struct _tree *right;
        struct _tree *parent;
} tree;

tree* allocate(int val)
{
        tree *node = calloc(1, sizeof(tree));
        node->data = val;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

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
        temp->parent = p_it;

        return (root);
}

/* recursive insert */
tree* insert_BST_recursive(tree *root, int val)
{
        if (root == NULL)
                return (allocate(val));

        if (val >= root->data) {
                tree *temp = insert_BST_recursive(root->right, val);
                root->right = temp;
                temp->parent = root;
        } else {
                tree *temp = insert_BST_recursive(root->left, val);
                root->left = temp;
                temp->parent = root;
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

void _inorder(tree *root)
{
        if (root == NULL)
                return;

        _inorder(root->left);
        printf("%d ", root->data);
        _inorder(root->right);
}

void print_inorder(tree *root)
{
        _inorder(root);
        printf("\n");
}

tree* next_inorder(tree *node)
{
        if (node == NULL)
                return (NULL);

        if (node->right) {
                tree *temp = node->right;
                while (temp && temp->left)
                        temp = temp->left;
                return (temp);
        } else {
                tree *temp = NULL;
                while (node) {
                        temp = node->parent;
                        if (temp && temp->left == node)
                                break;
                        node = temp;
                }
                return (temp);
        }

        return (NULL);
}


void iterative_inorder(tree *root)
{
        if (root == NULL)
                return;

        /* smallest node */
        while (root && root->left) {
                root = root->left;
        }

        while (root) {
                printf("%d ", root->data);
                root = next_inorder(root);
        }
        printf("\n");
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

        print_inorder(root);
        printf("\n\n");

        iterative_inorder(root);
        printf("\n\n");

        cleanup(&root);
        return 0;
}

