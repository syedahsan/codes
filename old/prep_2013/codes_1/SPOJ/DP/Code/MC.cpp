/* Making Change */
/* M[i] = MINj { M[ i - V[j] ] } + 1 */

#include <iostream>
#include <vector>

using namespace std;

int V[] = { 1, 2, 5, 10, 20, 50, 100 };

int main(int argc, char **argv)
{
	int N = sizeof(V)/sizeof(int);
	int C;
	cin >> C;

	vector<int> M(C+1);
	M[0] = 0;

	for( int i = 1; i <= C; i++ ) {
		int MIN = i;
		for( int j = 0; j < N; j++ ) {
			if( i-V[j] >= 0 && M[i-V[j]] < MIN )
				MIN = M[i-V[j]];
		}
		M[i] = MIN + 1;
	}

	for( int i = 0; i <= C; i++ ) {
		cout << i << " ----> " << M[i] << endl;
	}

	return 0;
}
