#include <stdio.h>
#include <string.h>

void reverse(char a[], int s, int e)
{
        char temp;

        while (s < e) {
                temp = a[s];
                a[s] = a[e];
                a[e] = temp;
                ++s;
                --e;
        }
}

void reverse_words(char a[])
{
        reverse(a, 0, strlen(a) - 1);
        printf("Debugged: %s\n", a);

        int it = 0;
        int isStart = 1; /* start of input */
        int inChar = 0; /* in between a token */
        int start;

        while (a[it] != '\0') {
                if (isStart && a[it] == ' ') {
                } else if (!inChar && a[it] != ' ') {
                        start = it;
                        inChar = 1; /* we've seen a character */
                        isStart = 0; /* we are no longer at the start */
                } else if (!isStart && inChar && a[it] == ' ') {
                        inChar = 0; /* no longer a character */
                        reverse(a, start, it-1);
                }
                ++it;
        }
        if (inChar) {
                reverse(a, start, it - 1);
        }

        return;
}

int main()
{
        char a[] = "This is a bad example";
        char b[] = "  This  is an amazing   example ";

        printf("Original: %s\n", a);
        reverse_words(a);
        printf("Reversed: %s\n", a);
        
        printf("\n");

        printf("Original: %s\n", b);
        reverse_words(b);
        printf("Reversed: %s\n", b);
}
