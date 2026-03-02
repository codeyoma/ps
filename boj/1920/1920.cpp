// https://www.acmicpc.net/problem/1920
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

/*
#include <unordered_set>
void set_solution()
{
    unordered_set<int> s;
    int n, m;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        if (s.count(temp))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}
*/

#include <algorithm>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int n, m;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        auto it = lower_bound(v.begin(), v.end(), t);

        if (it != v.end() && *it == t) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
