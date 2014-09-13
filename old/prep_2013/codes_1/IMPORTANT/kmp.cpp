/*
 * Knuth-Morris-Pratt
 * String Searching Algorithm
 * Wikipedia Implementation
 */

#include <iostream>
#include <vector>

#include <cstdio>

using namespace std;


/* Dynamic Programming */
vector<int> generate_partial_match(string W)
{
        vector<int> T (W.length());
        int j = 0;

        T[0] = -1;
        for (int i = 1; i < W.length(); ++i) {
                while (j > 0 && W[i] != W[j])
                        j = T[j-1];

                if (W[j] == W[i])
                        j++;

                T[i+1] = j;
        }

        return (T);
}

void print(vector<int> T)
{
        for (int i = 0; i < T.size(); ++i) {
                printf("%d ", T[i]);
        }
        printf("\n");
}

int kmp(string S, string W)
{
        int offset = -1;
/*        
        int my_T[] = {-1, 0, 0, 0, 0, 1, 2};
        vector<int> _T (my_T, my_T + sizeof(my_T) / sizeof(int));
*/
        vector<int> T = generate_partial_match(W);
        print(T);

        for (int m = 0, i = 0; m < S.length() && i < W.length(); ++i) {
                if (S[m+i] == W[i]) {
                        if (i == W.length() - 1)
                                offset = m;
                } else {
                        m = m + i - T[i];
                        i = T[i];
                }
        }

        return (offset);
}

int main()
{
        int N;
        scanf("%d\n", &N);

        while (N--) {
                string text, word;
                getline(cin, text);
                getline(cin, word);

                int offset = kmp(text, word);
                if (offset == -1) {
                        cout << "Cannot match" << endl;
                        continue;
                }
                
                cout << text << endl;
                for (int i = 0; i < offset; ++i)
                        cout << " ";
                cout << word << endl;
                cout << "Offset: " << offset << endl << endl;
        }

        return 0;
}
        
