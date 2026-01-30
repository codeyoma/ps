// https://www.acmicpc.net/problem/2458
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

    vector<vector<int>> g(n + 1, vector<int>(n + 1));

    for (int _ = 0; _ < m; ++_) {
        int a, b;
        cin >> a >> b;

        g[a][b] = -1;
        g[b][a] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (g[i][k] && g[k][j] && g[i][k] == g[k][j]) {
                    g[i][j] = g[i][k];
                }
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;

        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (!g[i][j]) {
                cnt++;
            }
        }

        if (cnt == 0) {
            answer++;
        }
    }

    cout << answer;
}
