// https://www.acmicpc.net/problem/2587
#include <iostream>
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

int partition(vector<int>& arr, int low, int high) {
    int pivot = high;
    int left  = low - 1;

    for (int right = low; right < high; ++right) {
        if (arr[right] <= arr[pivot]) {
            left++;
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[left + 1], arr[pivot]);
    return left + 1;
}

void qsort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        qsort(arr, low, pivot - 1);
        qsort(arr, pivot + 1, high);
    }
}

int main() {
    //   logic
    int         n = 5, sum = 0;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    qsort(arr, 0, n - 1);

    for (const auto& i: arr) {
        LOG << i << "\n";
    }

    cout << sum / n << "\n";
    cout << arr[2];
}
