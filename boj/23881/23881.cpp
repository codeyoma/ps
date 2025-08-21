// https://www.acmicpc.net/problem/23881
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

int main() {
    //   logic
    int n, k, count = 0;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = n; i > 0; --i) {
        int max_index = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[max_index] < arr[j]) {
                max_index = j;
            }
        }

        if (arr[i - 1] != arr[max_index]) {
            swap(arr[i - 1], arr[max_index]);
            count++;
            if (count == k) {
                cout << arr[max_index] << " " << arr[i - 1];
            }
        }
    }
    if (count < k) {
        cout << -1;
    }
}
