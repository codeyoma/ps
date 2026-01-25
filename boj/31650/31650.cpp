// https://www.acmicpc.net/problem/31650
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    FAST_IO

    //   logic
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    vector<int> t(n);
    vector<int> d(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    // S + t_{i} < c_{i}
    // S < c_{i} - t_{i}
    for (int i = 0; i < n; ++i) {
        d[i] = c[i] - t[i];
    }

    sort(d.begin(), d.end());

    while (q--) {
        int v, s;
        cin >> v >> s;

        int idx = upper_bound(d.begin(), d.end(), s) - d.begin();

        if (n - idx >= v) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
