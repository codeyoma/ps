// https://www.acmicpc.net/problem/24418
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
    int n, cnt = 0;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        v[0][i] = 1;
        v[i][0] = 1;
    }

    cnt += (n * 2) - 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
            cnt += v[i][j];
        }
    }

    cout << cnt + 1 << " " << n * n;

    return 0;
}
