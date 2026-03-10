// https://www.acmicpc.net/problem/1476
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

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

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

using namespace std;
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <vector>

int main() {
    FAST_IO;

    //   logic
    int e, s, m;

    cin >> e >> s >> m;

    if (e - 15 == 0) {
        e -= 15;
    }

    if (s - 28 == 0) {
        s -= 28;
    }

    if (m - 19 == 0) {
        m -= 19;
    }

    for (int i = 1; i <= 15 * 28 * 19; ++i) {
        if (i % 15 == e && i % 28 == s && i % 19 == m) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
