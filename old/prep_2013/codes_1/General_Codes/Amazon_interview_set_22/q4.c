#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _slist {
        int data;
        struct _slist *next;
} slist;

slist *allocate(int data)
{
        slist *node = calloc(1, sizeof(slist));
        node->data = data;
        node->next = NULL;
}

slist *insert(slist *start, int data)
{
        slist *node = allocate(data);
        node->next = start;

        return (node);
}

int myrand()
{
        return ((rand() % 9) + 1);
}

void print(slist *start)
{
        if (!start)
                return;
        while (start && start->next)
        {
                printf("%d -> ", start->data);
                start = start->next;
        }
        printf("%d\n", start->data);
}

void swap_data(slist *a, slist *b)
{
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
}

slist *swap_nodes(slist *start, slist *a, slist *b)
{
        if (!start || !a || !b || a == b )
                return (start);

        slist *a_prev = NULL;
        slist *b_prev = NULL;
        slist *node = start;

        while (node) {
                if ( a == node->next )
                        a_prev = node;
                if ( b == node->next )
                        b_prev = node;
                node = node->next;
        }
        /* a is start node, ie b is end node */
        if (!a_prev) {
                b->next = a->next;
                b_prev->next = a;
                a->next = NULL;
                return (b);
        } else if (!b_prev) {
                a->next = b->next;
                a_prev->next = b;
                b->next = NULL;
                return (a);
        } else {                
                node = b->next; /* temp */
                a_prev->next = b;
                b->next = a->next;
                b_prev->next = a;
                a->next = node;
                return (start);
        }
}

slist *kswap(slist *start, int k)
{
        if (!start)
                return;

        /* length */
        int len = 0;
        slist *node = start;
        while (node) {
                node = node->next;
                ++len;
        }

        if (k >= len)
                printf("LIST IS OF LESSER SIZE.\n");

        /* Kth node from start and end */
        int i;
        slist *kstart, *kend, *temp;
        kstart = kend = start;

        // kstart
        for (i = 0; i < k; i++) {
                kstart = kstart->next;
        }

        // kend
        temp = kstart;
        while (temp && temp->next) {
                temp = temp->next;
                kend = kend->next;
        }

        //swap_data(kstart, kend);
        start = swap_nodes(start, kstart, kend);

        return (start);
}

int main()
{
        slist *list = NULL;
        char line[1000];
        int a, k;

        scanf("%d", &k);

        //srand(time(NULL));
        while (scanf("%d", &a) && a != -1) {
                //list = insert(list, myrand());
                list = insert(list, a);
        }
        print(list);

        print(kswap(list, k-1));

        /* free() */
        return 0;
}
