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

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

#define N 1009

int connected_components(int A[N][N], int n)
{
    int flag = 0;
    int M[N][N]; 
    memset(M, -1, N*N*sizeof(int)); /* -1 == not visited */
    int i, j;
    queue<pair<int, int> > Q; 
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << i*n + j << endl;
            if (A[i][j] == 1 && M[i][j] == -1) {
                ++flag;
                Q.push(make_pair(i, j));
                while (!Q.empty()) {
                    int i1 = Q.front().first;
                    int j1 = Q.front().second;
                    Q.pop();
                    M[i1][j1] = flag;
                    int k, l;
                    for (k = -1; k <= 1; ++k) {
                        for (l = -1; l <= 1; ++l) {
                            if (i1 + k >=0 && i1 + k < n && j1 + l >= 0 && j1 + l < n) {
                                if (A[i1+k][j1+l] == 1 && M[i1+k][j1+l] == -1) {
                                    Q.push(make_pair(i1+k, j1+l));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return (flag);
} 

int main()
{
    int T;
    scanf("%d", &T);
    
    int n;
    int A[N][N];
    int i, j;
    while (T--) {
        memset(A, -1, N*N*sizeof(int));
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                scanf("%d", &A[i][j]);

        printf("scanning complete!\n");
        fflush(NULL);

        printf("%d\n", connected_components(A, n));
    }
    
    return 0;
}       
