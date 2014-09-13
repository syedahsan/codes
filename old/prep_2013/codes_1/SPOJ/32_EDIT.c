/* PROBLEM - EDIT
 * https://www.spoj.pl/problems/EDIT/
 *
 * Solution:
 *
 * consider the strings as binary strings as we dont really consider which alphabet is present.
 * all we need to worry about is that string is alternating.
 *
 * eg. AAaAaAA can be represented as 1101011 (caps - 1, non-caps - 0)
 * now this string can either be converted to 1010101 or 0101010
 * to convert to 1010101 we'll need to change 5 digits
 * where as to convert to 0101010 we'll only need 2 changes.
 *
 * Proposed Solution:
 * convert the given string to a binary string.
 * generate the two possible destinations for the given string.
 * calculate the number of edits required for the given string
 * to be converted to the generated string.
 * return the one which has minimum edits.
 *
 * NOTE: Since I am converting everything into 32 bit integers, the most it will work is for 31 chars long string.
 */

#include <stdio.h>
#include <string.h>

#define min(a, b) (a > b ? b : a)

int flip_bits(int N, int len)
{
        return (N ^ ((1 << len) - 1));
}

int convert_to_binary(char *str, int len)
{
        int N = 0, i;
        for (i=0; i<len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z')
                        N = N * 2 + 1;
                else if (str[i] >= 'a' && str[i] <= 'z')
                        N = N * 2 + 0;
                else
                        return -1; /* something is wrong */
        }

        return N;
}

int gen_dest_str(int len)
{
        int i, N = 0;
        for (i=0; i<len; i++)
                N = N * 2 + ((i+1) % 2);

        return N;
}

int count_set_bits(int N)
{
        int count = 0;
        while (N) {
                N &= (N-1);
                count++;
        }

        return count;
}

int compare(int src, int dest)
{
        return (count_set_bits(src ^ dest));
}

int edit(char *str)
{
        if (str == NULL || str[0] == '\0')
                return 0;

        int len = strlen(str);

        int src = convert_to_binary(str, len);
        int dest1 = gen_dest_str(len);
        int dest2 = flip_bits(dest1, len);

        return (min(compare(src, dest1), compare(src, dest2)));
}

int main()
{
        char inp[1002];

        while (scanf("%s", inp) != EOF)
                printf("%d\n", edit(inp));

        return 0;
}
