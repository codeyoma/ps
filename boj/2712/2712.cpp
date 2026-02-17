// https://www.acmicpc.net/problem/2712
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

#include <iomanip>
#include <string>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int t;
    cin >> t;

    while (t--) {
        float  n;
        string u;
        cin >> n >> u;

        cout << fixed << setprecision(4);
        if (u == "kg") {
            cout << n * 2.2046 << " lb\n";
        } else if (u == "l") {
            cout << n * 0.2642 << " g\n";
        } else if (u == "lb") {
            cout << n * 0.4536 << " kg\n";
        } else if (u == "g") {
            cout << n * 3.7854 << " l\n";
        }
    }

    return 0;
}
