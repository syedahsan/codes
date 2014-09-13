/* Problem Statement:
 * Given a paragraph of text, write a program to find the first shortest sub-segment that contains each of the given k words at least once. A segment is said to be shorter than other if it contains less number of words.
 *
 *  Ignore characters other than [a-z][A-Z] in the text. Comparison between the strings should be case-insensitive. 
 *
 *  If no sub-segment is found then the program should output “NO SUBSEGMENT FOUND”.
 *   
 *   Input format :
 *    
 *    First line of the input contains the text.
 *    Next line contains k , the number of  words given to be searched.
 *    Each of the next k lines contains a word.
 *     
 *      
 *      Output format :
 *       
 *       Print first shortest sub-segment that contains given k words , ignore special characters, numbers.If no sub-segment is found it should return “NO SUBSEGMENT FOUND”
 *        
 *        Sample Input :
 *         
 *         This is a test. This is a programming test. This is a programming test in any language.
 *         4
 *         this
 *         a
 *         test
 *         programming
 *          
 *          Sample Output :
 *           
 *           a programming test This
 *            
 *            Explanation :
 *            In this test case segment "a programming test. This" contains given four words. You have to print without special characters, numbers so output is "a programming test This".  Another segment "This is a programming test." also contains given  four words but have more number of words. 
 *             
 *
 *             Constraint :
 *
 *             Total number of character in a paragraph will not be more than 200,000.
 *             0 < k <= no. of words in paragraph.
 *             0 < Each word length < 15
 *
 */

/* Solution:
 * 
 * M[n][k+1]; all initialized with -1
 *
 * M[i][k] stores the span in which all the k letters are covered
 * M[i][k] = -1 if all k letters are not encountered yet;
 *
 * (j < k) M[i][j] stores how many steps earlier was Word[j] was encountered;
 *
 * M[i][j] = -1 if the Word[j] hasn't been encountered once
 * M[i][j] = 0 if Para[i] == Word[j] (case insensitive)
 * M[i][j] = M[i-1][j] + 1; ie 1 more than what it was at the previous step
 *
 * Calculate span after filling M[i][j] and store in M[i][k];
 * Now, find min (0<=i<=n) M[i][k] s.t. M[i][k] != -1 (some word is yet to be encountered)
 *
 * if found; print from i - M[i][k] to i; else print the desired message
 */

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define PARASIZE 200000
#define WORDSIZE 15

void shortest_subsegment(char Para[PARASIZE][WORDSIZE], int para_size, char **Words, int k)
{
        int i, j;
        
        int **M = calloc(para_size, sizeof(int *));
        for (i = 0; i < para_size; ++i) {
                M[i] = calloc(k + 1, sizeof(int)); /* we'll store span, and distances to individual words */
                memset(M[i], -1, (k+1)*sizeof(int));
        }

        for (i = 0; i < para_size; ++i) {
                for (j = 0; j < k; ++j) {
                        if (strcasecmp(Para[i], Words[j]) == 0) {
                                M[i][j] = 0;
                        } else {
                                if (i-1 >= 0 && M[i-1][j] != -1)
                                        M[i][j] = M[i-1][j] + 1;
                        }
                }
                /* calculate span */
                M[i][k] = INT_MIN;
                for (j = 0; j < k; ++j) {
                        if (M[i][j] == -1) { /* some word is yet to be matched */
                                M[i][k] = -1;
                                break;
                        }
                        if (M[i][j] > M[i][k])
                                M[i][k] = M[i][j];
                }
        }

        /* finding the minimum span */
        int min = INT_MAX;
        j = -1;
        for (i = 0; i < para_size; ++i) {
                if (M[i][k] != -1 && M[i][k] <= min) {
                        min = M[i][k];
                        j = i;
                }
        }

        /* printing the min span */
        if (j == -1)
                printf("NO SUBSEGMENT FOUND\n");
        else {
                for (i = j - min; i <= j; ++i)
                        printf("%s ", Para[i]);
                printf("\n");
        }

        /* free M */
        for (i = 0; i < para_size; ++i) {
                free(M[i]);
        }
        free(M);

        return;
}

int main()
{
        char Para[PARASIZE][WORDSIZE];
        int n, c;
        int spc = 0;
        int i = 0, j = 0;

        while (1) {
                c = getchar();
                if (((c >= 'A') && (c <= 'Z')) ||
                                ((c >= 'a') && (c <= 'z'))) {
                        Para[i][j++] = (char)c;
                        spc = 0;
                }
                if (c == ' ' && !spc) {
                        Para[i++][j] = '\0';
                        j = 0;
                        spc = 1;
                }
                if (c == '\n') {
                        Para[i++][j] = '\0';
                        break;
                }
        }
        n = i;

        int k;
        scanf("%d", &k);
        char **Words = calloc(k, sizeof(char*));
        for (i = 0; i < k; ++i) {
                Words[i] = calloc(WORDSIZE, sizeof(char));
                scanf("%s", Words[i]);
        }

        shortest_subsegment(Para, n, Words, k);

        for (i = 0; i < k; ++i) {
                free(Words[i]);
        }
        free(Words);
}
