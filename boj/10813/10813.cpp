// https://www.acmicpc.net/problem/10813
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

    int n, m;
    cin >> n >> m;

    vector<int> t(n + 1);

    for (int i = 1; i <= n; ++i) {
        t[i] = i;
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        swap(t[i], t[j]);
    }

    for (int i = 1; i <= n; ++i) {
        cout << t[i] << " ";
    }
}
