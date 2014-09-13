#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct _node {
        int data;
        struct _node *next;
} node;

void print(node *);

node *allocate(int val)
{
        node *temp = calloc(1, sizeof(node));
        temp->data = val;
        temp->next = NULL;

        return (temp);
}

node *push_front(node *start, int val)
{
        node *temp = allocate(val);

        if (start == NULL)
                return (temp);

        temp->next = start;

        return (temp);
}

node *push_back(node *start, int val)
{
        node *temp = allocate(val);

        if (start == NULL)
                return (temp);

        node *it = start;
        while (it && it->next)
                it = it->next;
        it->next = temp;

        return (start);
}

/* recursive reverse */
node *reverse(node *start)
{
        if (start == NULL)
                return (NULL);

        if (start->next == NULL)
                return (start);

        node *rest = reverse(start->next);
        start->next->next = start;
        start->next = NULL;

        return (rest);
}

int length(node *start)
{
        int len = 0;

        while (start) {
                start = start->next;
                ++len;
        }

        return (len);
}

/* O(n) + no extra space */
int is_palindrome(node *start)
{
        int ret = 1; /* hurrah!, it is a palindrome (lets assume)*/

        /* find middle element
         * ceil(n/2) */
        int i;
        node *it = start;
        
        int len = length(start);
        int mid = (int)ceil(len/2.0);

        for (i = 1; i < mid; ++i) {
                it = it->next;
        }

        /* keep the mid pointer */
        node *mid_ptr = it;

        /* reverse */
        node *end = reverse(it->next);
        it->next = NULL;
        it = end;

        /* compare */
        while (it) { /* ideally start should be equal or more than end */
                if (start->data != it->data) {
                        ret = 0;
                        break;
                } else {
                        start = start->next;
                        it = it->next;
                }
        }

        /* reverse the end list and create the original */
        end = reverse(end);
        mid_ptr->next = end;

        return (ret);
}

void print(node *start)
{
        while (start) {
                printf("%d->",start->data);
                start = start->next;
        }
        printf("NULL\n");
}

int main()
{
        int n;
        node *start = NULL;

        while (1) {
                scanf("%d", &n);
                if (n == -1)
                        break;
                start = push_front(start, n);
        }

        //print(start);

        printf("Is Palindrome: %s\n", (is_palindrome(start) ? "Yes" : "No"));
        
        //print(start);

        return 0;
}
