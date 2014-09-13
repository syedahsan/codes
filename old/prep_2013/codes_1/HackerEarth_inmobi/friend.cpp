#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> frienship(vector<vector<int> >& G, vector<int>& indegree, int n)
{
        vector<int> res;
        queue<int> Q;

        /* first push all the nodes with indegree 0 */
        for (int i = 0; i < n; ++i) {
                if (indegree[i] == 0) {
                        res.push_back(i);
                        indgree[i] == INT_MAX;
                }
        }

        min = INT_MAX;
        for (int i = 0 ; i < n; ++i) {
                if (indegree[i] < min)
                        min = indegree[i];
        }

        for (int i = 0; i < n; ++i) {
                if (indegree[i] == min) {
                        Q.push(i);
                }
        }

        while (!Q.empty()) {
                int v = Q.front();
                Q.pop();

                for (int i = 0; i < G[v].size(); ++i) {
                        --indegree[G[v][i]];
                }

                min = INT_MIN;
                for (int j = 0; 



int main()
{
        int n;
        scanf("%d", &n);

        vector<vector<int> > G(n, 0);
        vector<int> indegree(n, 0);

        int t;
        scanf("%d", &t);

        int a, b;
        while (t--) {
                scanf("%d %d", &a, &b);
                G[a].push_back(b);
                G[b].push_back(a);
                indegree[a]++;
                indegree[b]++;
        }

        vector<int> rest = frienship(G, indegree, n);

        return 0;
}
