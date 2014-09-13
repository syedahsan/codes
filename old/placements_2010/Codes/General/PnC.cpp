#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;


void generate_combinations_naive(vector<int> &inp) {
	int SIZE = inp.size();
	int limit = pow((double)2,SIZE);
	map< int, vector< vector<int> > > bitvec;  // MAP(size, vector of bitvector)
	vector<int> temp;
	int cnt = 0;

	for (int i=0; i<limit; i++) {
		for( int j=0; j<SIZE; j++ ) {
			if( ( i>>(SIZE-j-1) ) & 1 ) {
				cnt++;
				temp.push_back(1);
			}
			else
				temp.push_back(0);
		}

		bitvec[cnt].push_back(temp);
		temp.clear();
		cnt=0;
	}

//	cout << "Total Size: " << bitvec.size() << endl;
	for( int i=0; i<bitvec.size(); i++) {
		cout << "Size: " << i << endl << endl;
		for( int j=0; j<bitvec[i].size(); j++ ) {
//			cout << "Individual Size: " << bitvec[i].size() << endl;
			cout << "{ ";
			for( int k=0; k< (bitvec[i][j]).size(); k++) {
//				cout << "Size: " << (bitvec[i][j]).size() << endl;
				if(bitvec[i][j][k])
					cout << inp[k] << ", ";
			}
			cout << "}" << endl;
		}
		cout << endl;
	}
	return;
}
void print_vec( vector<int> &vec ) {

	cout << "{ ";
	for(int i=0; i<vec.size()-1; i++) {
		cout << vec[i] << ", ";
	}
	cout << vec[vec.size()-1] << " }" << endl;

	return;
}
void generate_permutations( const vector<int> &inp ) { 

	vector<int> mod = inp;
	print_vec(mod);
	int ind, lar_ind, temp;
	while(true) {
		
		//1. Find the largest position i such that a[i] < a[i+1] .
		ind = -1;
		for(int i=0; i<mod.size()-1; i++) {
			if( mod[i] < mod[i+1] )
				ind = i;
		}

		// Breaking Condition
		if(ind == -1)
			break;

		//2. Replace a[i] with the smallest value in a[i+1] to end · · · an that is bigger than the current value of a[i] .
		lar_ind = ind+1;
		for(int i=lar_ind; i<mod.size(); i++) {
			if( mod[i] > mod[ind] && mod[i] <= mod[lar_ind] )
				lar_ind = i;
		}
		temp = mod[ind];
		mod[ind] = mod[lar_ind];
		mod[lar_ind] = temp;

		//3. Reassign the values from the remaining elements ai+1 · · · an (and the original value of ai ) into increasing order.
		sort(mod.begin()+ind+1,mod.end());

		print_vec(mod);
	}
	return;
}

int main(int argc, char **argv) {

	if(argc!=2) {
		cout << "Usage: ./a.out <N>" << endl;
		return -1;
	}

	vector<int> inp;
	for( int i=0; i<atoi(argv[1]); i++)
		inp.push_back(i+1);

//	cout << "Generating Combinations ... " << endl;
//	generate_combinations_naive(inp);

//	cout << "Press any key to continue ... ";
//	getchar();
	cout << "\nGenerating Permutations ... " << endl;
	generate_permutations(inp);
	
	return 0;
}
