// https://www.acmicpc.net/problem/11404
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main() {
    FAST_IO

    //   logic
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(n + 1, _MAX));

    for (int i = 1; i <= n; ++i) {
        g[i][i] = 0;
    }

    for (int _ = 0; _ < m; ++_) {
        int a, b, c;
        cin >> a >> b >> c;

        if (g[a][b] > c) {
            g[a][b] = c;
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (g[i][k] == _MAX) {
                continue;
            }

            for (int j = 1; j <= n; ++j) {
                if (g[k][j] == _MAX) {
                    continue;
                }

                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == _MAX) {
                cout << 0 << " ";
            } else {
                cout << g[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
