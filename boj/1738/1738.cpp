// https://www.acmicpc.net/problem/1738
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

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

struct edge {
    int u;
    int v;
    int w;
};

void dfs(const vector<edge>& adj, vector<bool>& visit, int u) {
    visit[u] = true;

    for (const auto& e: adj) {
        if (e.u == u) {
            if (visit[e.v]) {
                continue;
            }

            dfs(adj, visit, e.v);
        }
    }
}

int main() {
    FAST_IO

    //   logic
    int n, m;
    cin >> n >> m;

    vector<edge> adj;
    vector<edge> r_adj;
    vector<int>  dist(n + 1, _MAX);
    vector<int>  predecessor(n + 1, _MAX);
    vector<bool> from_begin(n + 1, false);
    vector<bool> to_end(n + 1, false);

    iota(predecessor.begin(), predecessor.end(), 0);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({ u, v, -w });
        r_adj.push_back({ v, u, -w });
    }

    dist[1]        = 0;
    predecessor[1] = 0;

    dfs(adj, from_begin, 1);
    dfs(r_adj, to_end, n);

    for (int v = 0; v < n - 1; ++v) {
        bool has_updated = false;

        for (const auto& e: adj) {
            const auto [u, v, w] = e;

            if (dist[u] == _MAX) {
                continue;
            }

            if (dist[v] > dist[u] + w) {
                has_updated    = true;
                dist[v]        = dist[u] + w;
                predecessor[v] = u;
            }
        }

        if (!has_updated) {
            break;
        }
    }

    bool has_cycle = false;

    for (int v = 0; v < 1; ++v) {
        for (const auto& e: adj) {
            const auto [u, v, w] = e;

            if (dist[u] == _MAX) {
                continue;
            }

            if (dist[v] > dist[u] + w) {
                if (from_begin[v] && to_end[v]) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    if (dist[n] == _MAX) {
        cout << "-1";
        return 0;
    }

    vector<int> path;

    int start = n;
    while (start != 0 && start != _MAX) {
        path.push_back(start);
        start = predecessor[start];
    }

    for (vector<int>::reverse_iterator it = path.rbegin(); it != path.rend(); ++it) {
        cout << *it << " ";
    }
}
