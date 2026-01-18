// https://www.acmicpc.net/problem/10810
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

#include <iostream>
#include <vector>

int main() {
    FAST_IO

    //   logic

    int n, m;
    cin >> n >> m;

    vector<int> t(n + 1);

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int s = i; s <= j; ++s) {
            t[s] = k;
        }
    }

    for (int s = 1; s <= n; ++s) {
        cout << t[s] << " ";
    }
}
