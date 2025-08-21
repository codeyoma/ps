// https://www.acmicpc.net/problem/1026
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

int partition(vector<int>& a, int l, int h, function<bool(int, int)> cmp) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; ++right) {
        if (cmp(a[right], a[p])) {
            left++;
            swap(a[left], a[right]);
        }
    }

    left++;
    swap(a[left], a[p]);
    return left;
}

void qsort(vector<int>& a, int l, int h, function<bool(int, int)> cmp) {
    if (l < h) {
        int p = partition(a, l, h, cmp);
        qsort(a, l, p - 1, cmp);
        qsort(a, p + 1, h, cmp);
    }
}

int main() {
    //   logic

    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // a는 내림차, b는 오름차 (혹은 그 반대)
    qsort(a, 0, n - 1, [](int a, int b) { return a <= b; });
    qsort(b, 0, n - 1, [](int a, int b) { return a >= b; });

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += (a[i] * b[i]);
    }

    cout << answer;
}
