// https://www.acmicpc.net/problem/14659
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/14659/14659
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <vector>

int main() {
    fast_io();

    int n;
    cin >> n;
    vector<int> m(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    int max_a = MIN;

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (m[i] >= m[j]) {
                cnt++;
            } else {
                break;
            }
        }
        max_a = max(max_a, cnt);
    }
    cout << max_a;
}