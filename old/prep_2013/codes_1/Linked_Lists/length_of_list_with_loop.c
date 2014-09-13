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

int length_list(slist *start)
{
        if (!start)
                return (-1);

        int len = 1;
        /* detect loop first */
        slist *slow, *fast;
        slow = start->next;
        fast = start->next;
        if (fast) {
                fast = fast->next;
                ++len;
        }
        while (slow && fast && slow != fast) {
                slow = slow->next;
                fast = fast->next;
                ++len;
                if (fast) {
                        fast = fast->next;
                        ++len;
                }
        }

        if (!slow || !fast) /* no loop */
                return (len);

        /* length of loop */
        len = 1;
        fast = slow->next;
        while (slow != fast) {
                fast = fast->next;
                ++len;
        }

        /* http://stackoverflow.com/questions/2936213/explain-how-finding-cycle-start-node-in-cycle-linked-list-work */
        /* pointer to start of the loop & total length*/
        fast = start;
        while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
                ++len;
        }

        return (len);
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

int main()
{
        /* linked list with a loop */
        slist *loop_list = NULL;
        int i;
        
        srand(time(NULL));
        for (i = 0; i < 7; i++) {
                loop_list = insert(loop_list, myrand());
        }
        //print(loop_list);

        slist *node = loop_list;
        while (node && node->next) {
                node = node->next;
        }
        //print(node);
        node->next = loop_list->next->next;

        printf("%d\n", length_list(loop_list));

        return 0;
}
