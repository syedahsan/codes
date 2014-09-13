/* Integer Knapsack */
/* M[i,j] = MAX( M[i-1, j] , M[i-1, j-Si] + Vi ); Answer = Max_j_1_C M[n, j] */

#include <iostream>
#include <vector>
#include <utility>

typedef struct _cell {
	int val;
	int i, j;
} cell;

using namespace std;

void print(cell **M, int N, int C) {

	for ( int i = 0; i < N; i++ ) {
		for( int j = 0; j < C; j++ ) {
			cout << "( " << M[i][j].val << ", " << M[i][j].i << ", " << M[i][j].j << " ) ";
		}
		cout << endl;
	}

	return;
}

int main(int argc, char **argv)
{
	cout << "Enter the size value pairs, enter -1 to end" << endl;
	int C, S, V, N;
	vector < pair<int, int> > P;

	while(true) {
		cin >> S;
		if(S == -1) {
			break;
		}
		cin >> V;
		P.push_back(make_pair(S,V));
	}

	cout << "Enter the size of sack: ";
	cin >> C;
	N = P.size();

	/* Creating M[N+1][C+1]; */
	cell **M = new cell*[N];
	for ( int i = 0; i < N; i++ )
		M[i] = new cell[C];

	for ( int i = 0; i < N; i++ ) {
		for( int j = 0; j < C; j++ ) {
			if ( i-1 >= 0 ) {
				if ( j - P[i].first + 1 >= 0 ) {
					if ( M[i-1][j].val >  M[i-1][j-P[i].first].val + P[i].second ) {
						M[i][j].val = M[i-1][j].val;
						M[i][j].i   = i - 1;
						M[i][j].j   = j;
					}
					else {
						M[i][j].val = M[i-1][j-P[i].first].val + P[i].second;
						M[i][j].i   = i - 1;
						M[i][j].j   = j - P[i].first;
					}
				}
				else {
					M[i][j].val = M[i-1][j].val;
					M[i][j].i   = i - 1;
					M[i][j].j   = j;
				}		
			}
			else {
				if (j >= (P[i].first - 1))
					M[i][j].val = P[i].second;
				else
					M[i][j].val = 0;

				M[i][j].i   = 0;
				M[i][j].j   = 0;
			}
		}
	}

	print(M, N, C);
	
	int MAX = 0, x = N - 1, y;
	for ( int i = 0; i < C; i++ ) {
		if ( M[N-1][i].val > MAX ) {
			MAX = M[N-1][i].val;
			y = i;
		}
	}
	cout << "Optimal Solution: " << MAX << " " << x+1 << " " << y+1 << endl;

	/* Path Computation */
	while ( x+1 ) {
		int _x = x - 1;
		int _y = M[x][y].j;

		if ( _x < 0 || _y < 0 ) {
			if ( M[x][y].val != 0 )
				cout << x << " " << P[x].first << " " << P[x].second << endl;
			break;
		}
		
		if ( M[x][y].val != M[_x][_y].val )
			cout << x << " " << P[x].first << " " << P[x].second << endl;
		
		x = _x;
		y = _y;
	}

	return 0;
}
