#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int* median(int *start, int *end) {
	if (end - start + 1 <= 5) {
		sort(start, end+1);
		return start + (end - start)/2;
	}
	int mids[(end-start)/5+1], pos = 0;
	for (int* i = start; i < end; i+=5) {
		int* j = min(end+1, i+5);
		sort(i,j);
		mids[pos++] = *(i+(j-i)/2);
		cout << "Putting in mid: " << mids[pos-1] << endl;
	}
	int* mom = median(mids, mids+pos-1);
	//binder2nd<less<int> > isLessThan(less<int>(), (*mom)+1);
	int *ret = partition(start, end+1, bind2nd(less<int>(),(*mom) +1));
	int *posi = 0;
	for (int *i = start; i < ret; ++i) {
		if (*i == *mom) {
			posi = i;
			break;
		}
	}
	swap(*posi, *(ret-1));
	return ret-1;
	
}

int ith(int *start, int *end, int k) {
	int* pos = median(start, end);
	int location = (pos - start) + 1;
	if (location == k) {
		return *pos;
	} else if (location < k) {
		return ith(pos + 1, end, k - (location));
	} else {
		return ith(start, pos - 1, k);
	}

}

int main() {
	int n,k;
	cin >> n >> k;
	int arr[1000];
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	cout << ith(arr, arr + n - 1, k) << endl;
	return 0;
}
