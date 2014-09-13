/* Maximum Value Contiguouos Subsequence */
/* M[j] = max { M[j-1] + A[j], A[j] } */

#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX(a, b) ( (a>b) ? a : b )

using namespace std;

int main(int argc, char **argv)
{
	if(argc <= 2)
		return -1;
	vector<int> A;
	for(int i = 1; i < argc; i++)
		A.push_back(atoi(argv[i]));

	vector<int> M(A);

	for(int i = 1; i < M.size(); i++)
		M[i] = MAX(M[i-1] + A[i], A[i]);

	cout << M[M.size() - 1] << endl;

	return 0;
}
