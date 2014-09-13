#include <iostream>

using namespace std;

const int MAX = 100;
int Val[ MAX ], Seen[ MAX ];
//int count = 0 ;

int go(int n, int N) {
	if(n == N) {
		for(int i = 0; i < N; ++i) { 
			cout << Val[ i ] <<" ";
			if(Val[i]==8)
	//			count++;
		}
		cout << endl;
	}
	else {
		for(int i = 0; i < N; ++i) if(!Seen[ i ]) {
			++Seen[ i ];
			Val[ n ] = i + 1;
			go(n+1, N);
			--Seen[ i ];
		}
	}
}
void func(int N) {
	for(int i = 0; i < N; ++i) Seen[ i ] = 0;
	go(0, N);
	cout << count << endl;
}

