/*** Using Dynamic programming in O(n) ***/


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef struct sequence {
	int sum;
	int start;
	int end;
} seq;

seq LargestSubsequence( vector<int> Seq ) {

	int currSum=0, maxSum=-INT_MAX;
	int st=0, en=0;
	seq subseq;

	for (int i=0; i<Seq.size(); i++) {
		currSum += Seq[i];
		if(currSum > maxSum ) {
			maxSum = currSum;
			en = i+1;
			
			subseq.sum = maxSum;
			subseq.start = st;
			subseq.end = en;
		
		}
		if(currSum < 0) {
			currSum = 0;
			st = i+1;
		}
	}
	return subseq;
}
int main() {

	/* TAKING INPUT */
	int N,temp;
	cin >> N;
	vector <int> Arr;
	for(int i=0; i<N; i++) {
		cin >> temp;
		Arr.push_back(temp);
	}
	
	seq subseq = LargestSubsequence(Arr);

	for(int i=subseq.start; i<subseq.end; i++)
		cout << Arr[i] << " ";
	cout << endl << "Sum: " << subseq.sum << endl;
	
	return 0;
}
