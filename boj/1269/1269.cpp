// https://www.acmicpc.net/problem/1269
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

#define END   \
    return 0;

#include <vector>

template<typename T>
using VV = vector<vector<T>>;

template<typename T>
using V = vector<T>;

// typedef long long ll;
using LL  = long long;
using ULL = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr LL  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr LL  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <unordered_set>

int main() {
    FAST_IO;

    //   logic
    int n, m;
    cin >> n >> m;

    unordered_set<int> a, b;
    while (n--) {
        int t;
        cin >> t;
        a.insert(t);
    }
    while (m--) {
        int t;
        cin >> t;
        b.insert(t);
    }

    int cnt = 0;

    for (auto e: a) {
        if (b.find(e) == b.end()) {
            cnt++;
        }
    }

    for (auto e: b) {
        if (a.find(e) == a.end()) {
            cnt++;
        }
    }

    cout << cnt;

    END;
}
