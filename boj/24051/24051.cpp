// https://www.acmicpc.net/problem/24051
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

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j   = i - 1;

        while (j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            count++;
            LOG << arr[j] << endl;
            if (count == k) {
                cout << arr[j + 1];
            }
            j--;
        }
        if (arr[j + 1] != key) {
            count++;
        }
        arr[j + 1] = key;
        LOG << endl;
    }

    if (count < k) {
        cout << -1;
    }
}
