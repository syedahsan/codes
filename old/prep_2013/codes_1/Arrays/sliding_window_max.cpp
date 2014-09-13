#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

/* [ 5 2 4 6 3 7 8 10 9] K = 3 */
/* deque will store the indexes of the max */
vector<int> findKMax(vector<int>& arr, int k)
{
        deque<int> deq;
        vector<int> kmax;
        int i;

        if (arr.empty()) {
                /* kmax = empty */
        } else if (k >= arr.size()) {
                int max = INT_MIN;
                for (int i = 0; i < arr.size(); ++i)
                        if (arr[i] > max)
                                max = arr[i];
                kmax.push_back(max);
        } else {
                /* first fill k elements in deque for the first MAX */
                for(i = 0; i < k; ++i) {
                        /* this will work as we don't store a small element before a bigger element */
                        while (!deq.empty() && arr[deq.back()] <= arr[i]) {
                                deq.pop_back();
                        }
                        deq.push_back(i);
                }
                kmax.push_back(arr[deq.front()]);

                for (i = k; i < arr.size(); ++i) {

                        /* remove front element if doesn't belong to sliding window */
                        if (i - deq.front() > k)
                                deq.pop_front();

                        while(!deq.empty() && arr[deq.back()] <= arr[i])
                                deq.pop_back();

                        deq.push_back(i);

                        kmax.push_back(arr[deq.front()]);
                }
        }

        return kmax;
}

void print_arr(vector<int>& arr)
{
        cout << "[ ";
        for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
                cout << *it << ", ";
        cout << "]" << endl;
}

int main()
{
        vector<int> arr, kmax;
        int k;

        /* scanning */
        while (true) {
                cin >> k;
                if (k == -1)
                        break;
                arr.push_back(k);
        }
        cin >> k;
        print_arr(arr);

        kmax = findKMax(arr, k);

        cout << "Max Array:" << endl;
        print_arr(kmax);

        return 0;
}
