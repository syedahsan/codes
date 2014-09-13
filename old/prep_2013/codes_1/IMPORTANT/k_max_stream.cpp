#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        vector<int> kmax;
        int n;
        int k;
        
        cout << "Enter K: ";
        cin >> k;


        while (true) {
                cin >> n;
                if ( n == -1 )
                        break;

                k--;
                if (k > 0) {
                        kmax.push_back(n);
                } else if (k == 0) {
                        kmax.push_back(n);
                        make_heap(kmax.begin(), kmax.end(), greater<int>());
                } else {
                        if (n > kmax.front()) {
                                pop_heap(kmax.begin(), kmax.end(), greater<int>()); kmax.pop_back();
                                kmax.push_back(n); push_heap(kmax.begin(), kmax.end(), greater<int>());
                        }
                }
        }

        vector<int>::const_iterator it;
        cout << "K Max elements: " << endl;
        for (it = kmax.begin(); it != kmax.end(); ++it)
                cout << *it << " ";
        cout << endl;
}
