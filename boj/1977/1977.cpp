// https://www.acmicpc.net/problem/1977
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
    int sum = 0;
    int min = 0;
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; ++i) {
        int temp = sqrt(i);
        if (pow(temp, 2) == i) {
            if (min == 0) {
                min = i;
            }
            sum += i;
        }
    }

    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << "\n"
             << min;
    }

    return 0;
}
