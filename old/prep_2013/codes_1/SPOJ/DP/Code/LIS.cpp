/* Longest Increasing Subsequence */
/* L[i] = { MAX(L[j]) + 1 | j < i && A[j] < A[i] } */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main( int argc, char **argv )
{
	if( argc <= 1 )
		return 0;

	vector<int> A;
	for( int i = 1; i < argc; i++ )
		A.push_back(atoi(argv[i]));

	vector<int> L(A.size());
	for( int i = 0; i < A.size(); i++ ) {
		int MAX = 0;
		for( int j = 0; j < i; j++ ) {
			if( A[j] < A[i] && MAX < L[j] )
				MAX = L[j];
		}
		L[i] = MAX + 1;
	}

	int Size_LIS = 0;
	for( int i = 0; i < A.size(); i++ ) {
		cout << L[i] << endl;
		if( L[i] > Size_LIS )
			Size_LIS = L[i];
	}

	cout << "Size of LIS: " << Size_LIS << endl;

	return 0;
}
