// https://www.acmicpc.net/problem/2581
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

#include <cmath>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    vector<bool> t(10'001, true);
    t[0] = false;
    t[1] = false;

    for (int i = 2; i <= sqrt(10000); ++i) {
        if (t[i] == false) {
            continue;
        }

        for (int j = i + i; j <= 10000; j += i) {
            t[j] = false;
        }
    }

    int m, n, sum = 0, min_prime = 10000;
    cin >> m >> n;

    for (int i = m; i <= n; ++i) {
        if (t[i]) {
            sum += i;
            min_prime = min(min_prime, i);
        }
    }

    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << "\n"
             << min_prime;
    }

    return 0;
}
