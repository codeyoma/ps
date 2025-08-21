// https://www.acmicpc.net/problem/1427
#include <iostream>
#include <iterator>
using namespace std;

#ifdef LOCAL
#    define LOG clog
#else
struct nullstream : ostream {
    nullstream()
        : ostream(nullptr) {}
};
nullstream LOG;
#endif

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <algorithm>
#include <iostream>
#include <vector>

int partition(vector<int>& arr, int l, int h) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; ++right) {
        if (arr[right] <= arr[p]) {
            left++;
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[left + 1], arr[p]);
    return left + 1;
}

void qsort(vector<int>& arr, int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        qsort(arr, l, p - 1);
        qsort(arr, p + 1, h);
    }
}

int main() {
    //   logic
    int n;
    cin >> n;

    vector<int> arr;

    while (n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }

    qsort(arr, 0, arr.size() - 1);

    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it;
    }
}
