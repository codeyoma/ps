// https://www.acmicpc.net/problem/2217
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

int partition(vector<int>& a, int l, int h) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; ++right) {
        if (a[right] <= a[p]) {
            left++;
            swap(a[left], a[right]);
        }
    }

    left++;
    swap(a[left], a[p]);
    return left;
}

void sort(vector<int>& a, int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);

        sort(a, l, p - 1);
        sort(a, p + 1, h);
    }
}

int main() {
    //   logic
    int n;
    cin >> n;
    vector<int> rope(n);

    for (int i = 0; i < n; ++i) {
        cin >> rope[i];
    }

    int max_w = MIN;
    sort(rope, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        max_w = max(max_w, rope[i] * (n - i));
    }

    cout << max_w;
}
