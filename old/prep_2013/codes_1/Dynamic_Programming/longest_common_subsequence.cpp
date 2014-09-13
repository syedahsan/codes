#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

inline int MAX(int a, int b)
{
        return (a > b ? a : b);
}

void print(vector<vector<int> > C, string a, string b, int m, int n)
{
        cout << "  ";
        for (int i = 0; i < n; ++i)
                cout << b[i] << " ";
        cout << endl;
        for (int i = 0; i < m; ++i) {
                cout << a[i] << " ";
                for (int j = 0; j < n; ++j) {
                        cout << C[i][j] << " ";
                }
                cout << endl;
        }
}

/*
 * LCS[i, j] = Longest increasing subsequence between
 * a[0..i-1] and b[0..j-1]
 *
 * LCS[m, n] = 1 + LCS[m-1, n-1] if a[i] == b[j]
 * LCS[m, n] = max(LCS[m-1, n], LCS[m, n-1])
 *
 * LCS will hold the maximum length at each (i, j) pair
 * we'll need to backtrack to get the lcs(s)
 *
 */

vector<string> backtrack(vector<vector<int> > C, string a, string b, int i, int j)
{
        vector<string> lcss;

        if (i == -1 || j == -1) {
                lcss.push_back(string(""));
                return (lcss);
        }

        if (a[i] == b[j]) {
                vector<string>::iterator it;
                lcss = backtrack(C, a, b, i-1, j-1);
                for (it = lcss.begin(); it != lcss.end(); ++it) {
                        *it += a[i];
                }

                return (lcss);
        }

        int A, B;
        A = (i - 1 >= 0) ? C[i-1][j] : 0;
        B = (j - 1 >= 0) ? C[i][j-1] : 0;
        if (A >= B) {
                vector<string> res = backtrack(C, a, b, i-1, j);
                for (int k = 0; k < res.size(); ++k) {
                        lcss.push_back(res[k]);
                }
        }
        if (B >= A) {
                vector<string> res = backtrack(C, a, b, i, j-1);
                for (int k = 0; k < res.size(); ++k) {
                        lcss.push_back(res[k]);
                }
        }

        return (lcss);
}

vector<string> lcs(string a, string b)
{
        /* create a C[M][N] */
        vector<vector<int> > C;
        int m = a.length();
        int n = b.length();
        C.resize(m);
        for (int i = 0; i < m; ++i)
                C[i].resize(n);
        /* C[i][j] is ready */

        /* Building C matrix */
        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (a[i] == b[j]) {
                                if (i - 1 >= 0 && j - 1 >= 0)
                                        C[i][j] = C[i-1][j-1] + 1;
                                else
                                        C[i][j] = 1;
                        } else {
                                int A, B;
                                A = (i - 1 >= 0) ? C[i-1][j] : 0;
                                B = (j - 1 >= 0) ? C[i][j-1] : 0;

                                C[i][j] = MAX(A, B);
                        }
                }
        }

        print(C, a, b, m, n);
        cout << endl;

        vector<string> lcss = backtrack(C, a, b, m-1, n-1);
        return (lcss);
}

int main()
{
        string a, b;
        cin >> a >> b;
        cout << a << endl << b << endl << endl;

        vector<string> lcss = lcs(a, b);

        for(vector<string>::iterator it = lcss.begin(); it != lcss.end(); ++it)
                cout << *it << endl;

        return 0;
}
