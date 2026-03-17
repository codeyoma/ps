// https://www.acmicpc.net/problem/6504
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
    vector<int> f(2);
    f[0] = 1;
    f[1] = 2;

    for (int i = 2;; ++i) {
        f.push_back(f[i - 2] + f[i - 1]);
        if (f.back() >= 25'000) {
            break;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        int bit = 0;
        for (auto it = f.rbegin(); it != f.rend(); ++it) {
            if (k - *it >= 0) {
                k -= *it;

                if (it + 1 != f.rend()) {
                    bit += *(it + 1);
                }
            }
        }
        cout << bit << "\n";
    }

    return 0;
}
