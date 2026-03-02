// https://www.acmicpc.net/problem/10815
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

#include <algorithm>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    int n, m;
    cin >> n;

    vector<int> card(n);

    for (int i = 0; i < n; ++i) {
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        auto it = lower_bound(card.begin(), card.end(), t);

        if (it != card.end() && *it == t) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    return 0;
}
