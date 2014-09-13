#include <stdio.h>
#include <string.h>
#include <stdlib.h>

inline void swap(char *str, int i, int j)
{
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
}

char* reverse(char *str)
{
        int len = strlen(str);
        int i = 0, j = len - 1;

        while (i <= j) {
                swap(str, i, j);
                i++;
                j--;
        }
        str[len] = '\0';

        return str;
}

int main()
{
        char *str = "This is a null terminated string\0";
        printf("[NORMAL] %s\n", str);

        char *rev = reverse(strdup(str));
        printf("[REVERSE] %s\n", rev);

        free(rev);
        
        return 0;
}
