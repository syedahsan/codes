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

/* print singly linked list
 * right is the next ptr;
 */
void print_sll(tree *ll_start)
{
        while (ll_start) {
                printf("%d -> ", ll_start->data);
                ll_start = ll_start->right;
        }
        printf("(Null)\n");
}

/* print doubly linked list
 * right is next ptr;
 * left is the prev ptr;
 */
void print_dll(tree *dll)
{
        tree *it;
        while (dll) {
                printf("%d <=> ", dll->data);
                it = dll;
                dll = dll->right;
        }
        printf("(Null)\n");
        printf("Reverse: ");
        while (it) {
                printf("%d <=> ", it->data);
                it = it->left;
        }
        printf("(Null)\n");
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

tree* tree_to_sll(tree *root)
{
        if (root == NULL)
                return (NULL);

        tree *lt = tree_to_sll(root->left);
        tree *rt = tree_to_sll(root->right);
        tree *ret = root;

        if (lt) {
                ret = lt; /* if left tree is there; then it should be returned */
                while (lt && lt->right)
                        lt = lt->right;
                lt->right = root;
        }
        root->right = rt;
        root->left = NULL;

        return (ret);
}

tree *tree_to_dll(tree *root)
{
        if (root == NULL)
                return (NULL);

        tree *lt = tree_to_dll(root->left);
        tree *rt = tree_to_dll(root->right);
        tree *ret = root;

        if (lt) {
                ret = lt;
                while (lt && lt->right)
                        lt = lt->right;
                lt->right = root;
        }
        root->left = lt;
        root->right = rt;
        if (rt)
                rt->left = root;

        return (ret);
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

        //tree *start = tree_to_sll(root);
        //print_sll(start);
        
        tree *start = tree_to_dll(root);
        print_dll(start);

        //cleanup(&root);
        return 0;
}

