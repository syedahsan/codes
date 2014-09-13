#include <stdio.h>
#include <stdlib.h>

typedef struct _dll {
        int data;
        struct _dll *next;
        struct _dll *prev;
} dll;

static dll *allocate(int val)
{
        dll *node = calloc(1, sizeof(dll));
        node->data = val;
        node->next = NULL;
        node->prev = NULL;

        return (node);
}

static void free_and_nullify(dll **ptr)
{
        free(*ptr);
        *ptr = NULL;
}

dll *push_front(dll *start, int val)
{
        dll *node = allocate(val);

        if (start == NULL)
                return (node);

        node->next = start;
        start->prev = node;

        return (node);
}

/* start pointer is only needed because someone can 
 * delete the start pointer as well, then we'll need
 * to return a new start pointer;
 * otherwise only the delete pointer was needed;
 */
dll *delete_node(dll *start, dll *del)
{
        if (del == NULL)
                return (start);

        if (del->prev == NULL && del->next == NULL) { /* delete is the only node */
                free_and_nullify(&del);
                return (NULL);
        }

        /* not comparing with start pointer since we don't want to use it */
        if (del->prev == NULL) { /* del is the start pointer */
                start = del->next;
                start->prev = NULL;
                free_and_nullify(&del);
                return (start);
        }

        if (del->next == NULL) { /* del is the end pointer */
                dll *temp = del->prev;
                temp->next = NULL;
                free_and_nullify(&del);
                return (start);
        }

        /* normal case */
        {
                dll *p = del->prev;
                dll *n = del->next;

                p->next = n;
                n->prev = p;

                free_and_nullify(&del);
                return (start);
        }
}

dll *search(dll *start, int val)
{

        while (start) {
                if (start->data == val)
                        return (start);
                start = start->next;
        }

        return (NULL);
}

void cleanup(dll **start)
{
        dll *it = *start;

        while (it) {
                dll *temp = it->next;
                free_and_nullify(&it);
                it = temp;
        }

        *start = NULL;
}

void remove_duplicates(dll *start)
{
        if (start == NULL)
                return;

        while (start) {
                dll *it = start->next;
                while (it) {
                        if (start->data == it->data) { /* it is a duplicate */
                                /* it->prev can never be NULL */
                                it->prev->next = it->next;
                                if (it->next)
                                        it->next->prev = it->prev;
                                dll *del = it;
                                it = it->next;
                                free_and_nullify(&del);
                        }
                        else {
                                it = it->next;
                        }
                }
                start = start->next;
        }

        return;
}

void print(dll *start)
{
        while (start) {
                printf("%d <=> ", start->data);
                start = start->next;
        }
        printf("(Null)\n");
}

void print_dll(dll *start)
{
        dll *end = start;
        while (start) {
                printf("%d <=> ", start->data);
                end = start;
                start = start->next;
        }
        printf("(Null)");
        printf("\t|\t");
        while (end) {
                printf("%d <=> ", end->data);
                end = end->prev;
        }
        printf("(Null)\n");
}


int main()
{
        int n;
        dll *start = NULL;

        printf("Enter numbers to insert into DLL; enter \"-1\" to exit\n");
        while (1) {
                scanf("%d", &n);
                if (n == -1)
                        break;
                start = push_front(start, n);
        }

        printf("Your DLL looks like\n");
        print(start);

/*
        printf("Enter number you'd like to delete from the dll: ");
        scanf("%d", &n);
        start = delete_node(start, search(start, n));
        print(start);
        //print_dll(start);
*/

        remove_duplicates(start);
        print(start);
        //print_dll(start);

        cleanup(&start);
        return 0;
}
