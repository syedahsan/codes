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
        while (start)
        {
                printf("%d -> ", start->data);
                start = start->next;
        }
        printf("(NULL)\n");
}

int length(slist *node)
{
        int len = 0;
        while (node) {
                node = node->next;
                ++len;
        }

        return (len);
}

#define abs(x) (((x) > 0) ? (x) : (-1 * (x)))

slist *merge_point(slist *a, slist *b)
{
        if (a == NULL || b == NULL)
                return (NULL);

        int i;
        int len_a = length(a);
        int len_b = length(b);
        int diff;

        if (len_a > len_b) {
                diff = len_a - len_b;
                for ( i = 0; i < diff; ++i )
                        a = a->next;

                while ( a && b && a != b ) {
                        a = a->next;
                        b = b->next;
                }

                if ( a != b ) /* no loop */
                        return (NULL);
                else
                        return (a);
        } else {
                diff = len_b - len_a;
                for ( i = 0; i < diff; ++i )
                        b = b->next;

                while ( a && b && a != b ) {
                        a = a->next;
                        b = b->next;
                }

                if ( a != b ) /* no loop */
                        return (NULL);
                else
                        return (a);
        }
}



int main()
{
        /* linked list with a loop */
        slist *list_a = NULL;
        slist *list_b = NULL;
        int i;
        int len_a, len_b;
        
        srand(time(NULL));
        len_a = myrand();
        for (i = 0; i < len_a; ++i) {
                list_a = insert(list_a, myrand());
        }
        print(list_a);

        len_b = myrand();
        for (i = 0; i < len_b; ++i) {
                list_b = insert(list_b, myrand());
        }
        print(list_b);

        /* create a merge point */
        slist *temp = list_b;
        while (temp && temp->next)
                temp = temp->next;
        slist *temp_a = list_a;
        int merge_pt = ((rand() % len_a) + 1);
        for (i = 0; i < merge_pt; ++i)
                temp_a = temp_a->next;
        if (temp) {
                temp->next = temp_a;
        }
        // temp_a is the merge point

        temp = merge_point(list_a, list_b);

        if (temp)
                printf("Original Merge Point: %d | Detected Merge Point: %d | Are they same?: %s\n", temp_a->data, temp->data, ((temp_a == temp) ? "True" : "False"));
        else
                printf("No Merge Point | Original Merge Point: %p | Detected Merge Point: %p\n", temp_a, temp);

        return 0;
}
