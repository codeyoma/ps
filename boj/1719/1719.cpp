// https://www.acmicpc.net/problem/1719
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

struct Node {
    int cost;
    int next;
};

int main() {
    FAST_IO

    //   logic

    int n, m;
    cin >> n >> m;

    vector<vector<Node>> g(n + 1, vector<Node>(n + 1, { _MAX, 0 }));

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = { c, b };
        g[b][a] = { c, a };
    }

    for (int i = 1; i <= n; ++i) {
        g[i][i] = { 0, i };
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (g[i][k].cost == _MAX) {
                continue;
            }
            for (int j = 1; j <= n; ++j) {
                if (g[k][j].cost == _MAX) {
                    continue;
                }

                if (g[i][j].cost > g[i][k].cost + g[k][j].cost) {
                    g[i][j] = { g[i][k].cost + g[k][j].cost, g[i][k].next };
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                cout << "- ";
            } else {
                cout << g[i][j].next << " ";
            }
        }
        cout << "\n";
    }
}
