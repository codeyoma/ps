// https://www.acmicpc.net/problem/1978
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
    vector<bool> m(1001, true);
    m[1] = false;
    m[0] = false;

    for (int i = 2; i <= sqrt(1001); ++i) {
        if (m[i] == false) {
            continue;
        }

        for (int j = i + i; j <= 1000; j += i) {
            m[j] = false;
        }
    }

    int n;
    int cnt = 0;

    cin >> n;

    while (n--) {
        int t;
        cin >> t;

        if (m[t]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
