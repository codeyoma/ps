// https://www.acmicpc.net/problem/3009
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

#include <unordered_set>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    unordered_set<int> x_set;
    unordered_set<int> y_set;

    int n = 3;

    while (n--) {
        int x, y;
        cin >> x >> y;

        if (x_set.find(x) == x_set.end()) {
            x_set.insert(x);
        } else {
            x_set.erase(x);
        }

        if (y_set.find(y) == y_set.end()) {
            y_set.insert(y);
        } else {
            y_set.erase(y);
        }
    }

    cout << *x_set.begin() << " " << *y_set.begin();

    return 0;
}
