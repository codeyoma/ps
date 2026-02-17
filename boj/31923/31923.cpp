// https://www.acmicpc.net/problem/31923
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
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> pv(n);
    vector<int> qv(n);
    vector<int> av(n);

    for (int i = 0; i < n; ++i) {
        cin >> pv[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> qv[i];
    }

    int r = q - p;

    bool check = true;

    if (r == 0) {
        for (int i = 0; i < n; ++i) {
            if (pv[i] != qv[i]) {
                cout << "NO";
                return 0;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int gap = pv[i] - qv[i];

            if (gap % r != 0 || gap / r < 0) {
                cout << "NO";
                return 0;
            }

            av[i] = gap / r;
        }
    }

    cout << "YES\n";

    for (const auto& e: av) {
        cout << e << " ";
    }

    return 0;
}
