/* 
 Given a 2–d matrix , which has only 1’s and 0’s in it. Find the total number of connected sets in that matrix.
 
 
Explanation:
Connected set can be defined as group of cell(s) which has 1 mentioned on it and have at least one other cell in that set with which they share the neighbor relationship. A cell with 1 in it and no surrounding neighbor having 1 in it can be considered as a set with one cell in it. Neighbors can be defined as all the cells adjacent to the given cell in 8 possible directions ( i.e N , W , E , S , NE , NW , SE , SW direction ). A cell is not a neighbor of itself.
 
 
Input format :
 
First line of the input contains T , number of test-cases.
Then follow T testcases. Each testcase has given format.
N [ representing the dimension of the matrix N X N ].
Followed by N lines , with N numbers on each line.
 
 
 
Ouput format :
 
For each test case print one line ,  number of connected component it has.
 
Sample Input :
 
4
4
0 0 1 0
1 0 1 0
0 1 0 0
1 1 1 1
4
1 0 0 1
0 0 0 0
0 1 1 0
1 0 0 1
5
1 0 0 1 1
0 0 1 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
8
0 0 1 0 0 1 0 0
1 0 0 0 0 0 0 1
0 0 1 0 0 1 0 1
0 1 0 0 0 1 0 0
1 0 0 0 0 0 0 0
0 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
0 0 0 0 0 0 0 0
 
Sample output :
 
1
3
3
9
 
Constraint :
 
0 < T < 6 
0 < N < 1009 
*/
/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#include <stdio.h>
#include <string.h>

#define N 1009

int A[N][N];
int M[N][N]; /* visited array */

void DFS(int i, int j, int n)
{
        M[i][j] = 1;
        int k, l, a, b;

        for (k = -1; k <= 1; ++k) {
                for (l = -1; l <= 1; ++l) {
                        a = i + k;
                        b = j + l;
                        if (a >= 0 && a < n && b >= 0 && b < n && A[a][b] && !M[a][b]) {
                                DFS(a, b, n);
                        }
                }
        }

        return;
}

int connected_components(int n)
{
    int count = 0;
    memset(M, 0, N*N*sizeof(int));
    int i, j;
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (A[i][j] && !M[i][j]) {
                ++count;
                DFS(i, j, n);
            }
        }
    }
    
    return (count);
} 

int main()
{
    int T;
    scanf("%d", &T);
    
    int n;
    int i, j;
    while (T--) {
        memset(A, 0, N*N*sizeof(int));
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                scanf("%d", &A[i][j]);

        printf("%d\n", connected_components(n));
    }
    
    return 0;
}       
