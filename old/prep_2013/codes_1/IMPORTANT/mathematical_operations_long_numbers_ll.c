#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _slist {
        int data;
        struct _slist *next;
} slist;

#define TRUE 1
#define FALSE 0

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

slist *push_front(slist *start, int data)
{
        return (insert(start, data));
}

slist *push_back(slist *start, int data)
{
        slist *node = allocate(data);

        if (start == NULL)
                return (node);

        slist *it = start;
        while (it && it->next) {
                it = it->next;
        }
        it->next = node;

        return (start);
}

/* returns new start node */
slist *pop_back(slist *start)
{
        if (start == NULL)
                return (NULL);

        if (start->next == NULL) {
                free(start);
                return (NULL);
        }

        slist *it = start;
        slist *prev = start;
        while (it && it->next) {
                prev = it;
                it = it->next;
        }

        prev->next = NULL;
        free(it);
        return (start);
}

int last(slist *start)
{
        if (start == NULL)
                return (10); /* double digit number to indicate error */

        while (start && start->next)
                start = start->next;

        return (start->data);
}

unsigned int is_negative(slist *start)
{
        if (start == NULL)
                return (FALSE);

        int l = last(start);
        if (l == -1) {
                return (TRUE);
        } else if (l == 10) { /* somehow start was NULL */
                return (FALSE);
        } else {
                return (FALSE);
        }
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

void cleanup(slist **start)
{
        slist *it = *start;
        while (it) {
                slist *temp = it->next;
                free(it);
                it = temp;
        }

        *start = NULL;
}

slist* copy(slist *node)
{
        slist *start = NULL;
        while (node) {
                start = push_back(start, node->data);
                node = node->next;
        }

        return (start);
}

/* basic a + b; where both a & b are positive numbers */
slist* _add(slist *a, slist *b)
{
        slist *sum = NULL;
        
        if (a == NULL && b == NULL) {
                sum = insert(sum, 0);
                return (sum);
        }

        if (a == NULL)
                return (copy(b));

        if (b == NULL)
                return (copy(a));

        unsigned int carry = 0;

        while (a && b) {
                sum = push_back(sum, ((carry + a->data + b->data) % 10));
                carry = (carry + a->data + b->data) / 10;
                a = a->next;
                b = b->next;
        }

        if (a == NULL && b == NULL) {
                if (carry)
                        sum = push_back(sum, carry);
                return (sum);
        } else if (a == NULL) {
                while (b) {
                        sum = push_back(sum, ((carry + b->data) % 10));
                        carry = (carry + b->data) / 10;
                        b = b->next;
                }
                if (carry)
                        sum = push_back(sum, carry);
                return (sum);
        } else if (b == NULL) {
                while (a) {
                        sum = push_back(sum, ((carry + a->data) % 10));
                        carry = (carry + a->data) / 10;
                        a = a->next;
                }
                if (carry)
                        sum = push_back(sum, carry);
                return (sum);
        } else;
}

/* don't feed list with sentinal characters
 * works for positive lists only
 */
slist *greater(slist *a, slist *b)
{
        if (a == NULL && b == NULL) /* lists of same length */
                return (NULL);

        if (a == NULL)
                return (b);

        if (b == NULL)
                return (a);

        slist *ret = greater(a->next, b->next);
        if (ret == NULL) {
                if (a->data == b->data)
                        return (NULL);
                else
                        return ((a->data > b->data) ? a : b);
        } else if (ret == a->next) {
                return (a);
        } else if (ret == b->next) {
                return (b);
        } else {
                /* error */
        }

}

/* basic a - b; where both a and b are positive numbers */
slist* _substract(slist *a, slist *b)
{
        slist *diff = NULL;

        if (a == NULL && b == NULL) {
                diff = insert(diff, 0);
                return (diff);
        }

        if (a == NULL) {
                diff = copy(b);
                diff = push_back(diff, -1);
                return (diff);
        }

        if (b == NULL) {
                return (copy(a));
        }

        unsigned int carry = 0;
        unsigned int negative = 0;
        slist *g = greater(a, b); /* greater pointer */
        slist *l = NULL;          /* lesser pointer */
        
        if (g == NULL) { /* both are equal */
                diff = insert(diff, 0);
                return (diff);
        } else if (g == a) {
                l = b;
        } else {
                l = a;
                negative = 1;
        }

        while (g && l) {
                if ((g->data - carry) >= l->data) {
                        diff = push_back(diff, (g->data - carry - l->data));
                        carry = 0;
                } else {
                        diff = push_back(diff, (10 + g->data - carry - l->data));
                        carry = 1;
                }
                g = g->next;
                l = l->next;
        }

        if (g == NULL && l == NULL) {
                /* diff has correct result */
        } else if (l == NULL) {
                while (g) {
                        diff = push_back(diff, g->data - carry);
                        carry = 0;
                }
        } else if (g == NULL) {
                /* something went wrong, we shouldn't have been here */
                /* err!!? */
        } else {
                /* not possible; */
        }

        if (negative)
                diff = push_back(diff, -1);

        return (diff);
}

slist* add(slist *a, slist *b)
{
        slist *sum = NULL;
        if (is_negative(a) && is_negative(b)) {
                pop_back(a);
                pop_back(b);
                sum = _add(a, b);
                sum = push_back(sum, -1);
                a = push_back(a, -1);
                b = push_back(b, -1);
        } else if (is_negative(a)) {
                pop_back(a);
                sum = _substract(b, a);
                a = push_back(a, -1);
        } else if (is_negative(b)) {
                pop_back(b);
                sum = _substract(a, b);
                b = push_back(b, -1);
        } else {
                sum = _add(a, b);
        }

        return (sum);
}

slist* substract(slist *a, slist *b)
{
        slist *diff = NULL;
        if (is_negative(a) && is_negative(b)) {
                pop_back(a);
                pop_back(b);
                diff = _substract(b, a);
                a = push_back(a, -1);
                b = push_back(b, -1);
        } else if (is_negative(a)) {
                pop_back(a);
                diff = _add(a, b);
                diff = push_back(diff, -1);
                a = push_back(a, -1);
        } else if (is_negative(b)) {
                pop_back(b);
                diff = _add(a, b);
                b = push_back(b, -1);
        } else {
                diff = _substract(a, b);
        }

        return (diff);
}



void print_num(slist *num)
{
        if (num == NULL)
                return;
        print_num(num->next);
        if (num->data == -1) /* sentinal value for negative */
                printf("-");
        else
                printf("%d", num->data);
}

/* works only for positive number */

int main()
{
        slist *a = NULL;
        slist *b = NULL;
        int negative = 0;
        int first_valid_digit = 0;
        int first = 1;
        char c;

        while ((c = getchar()) != '\n') {
                if ((c == '-') && (negative == 0) && first)
                        negative = 1;
                else {
                        unsigned int x = c - '0';
                        if (x >= 1 && x <= 9) {
                                first_valid_digit = 1;
                                a = insert(a, x);
                        } else if (x == 0 && first_valid_digit) {
                                a = insert(a, x);
                        }
                }
                first = 0;
        }
        if (negative && length(a))
                a = push_back(a, -1);

        negative = 0;
        first_valid_digit = 0;
        first = 1;
        
        while ((c = getchar()) != '\n') {
                if ((c == '-') && (negative == 0) && first)
                        negative = 1;
                else {
                        unsigned int x = c - '0';
                        if (x >= 0 && x <= 9) {
                                first_valid_digit = 1;
                                b = insert(b, x);
                        } else if (x == 0 && first_valid_digit) {
                                b = insert(b, x);
                        }
                }
        }
        if (negative && length(b))
                b = push_back(b, -1);

        print(a);
        print(b);

        slist *sum = add(a, b);
        slist *diff = substract(a, b);

        print(sum);
        print(diff);

        printf("Sum:\n");
        print_num(sum);
        printf("\n");

        printf("Diff:\n");
        print_num(diff);
        printf("\n");

        cleanup(&a);
        cleanup(&b);
        cleanup(&sum);
        cleanup(&diff);

        return 0;
}
