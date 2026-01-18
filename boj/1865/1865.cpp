// https://www.acmicpc.net/problem/1865
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2")
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// typedef long long ll;
//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

typedef struct Node {
    int from;
    int to;
    int cost;
} Node;

int main() {
    fast_io();

    //   logic
    int tc;

    cin >> tc;

    while (tc--) {
        int n, m, w, max_e;

        cin >> n >> m >> w;
        max_e = m * 2 + w;

        vector<int>  dist(501, 0);
        vector<Node> adj;
        adj.reserve(max_e);

        for (int i = 0; i < m; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            adj.push_back({ s, e, t });
            adj.push_back({ e, s, t });
        }

        for (int i = 0; i < w; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            adj.push_back({ s, e, -t });
        }

        bool has_cycle = false;
        {
            for (int v = 0; v < n; ++v) {
                bool has_update = false;

                for (int e = 0; e < max_e; ++e) {
                    const auto [from, to, cost] = adj[e];

                    if (dist[to] > dist[from] + cost) {
                        dist[to]   = dist[from] + cost;
                        has_update = true;

                        if (v == n - 1) {
                            has_cycle = true;
                            break;
                        }
                    }
                }

                if (!has_update) {
                    break;
                }
            }
        }

        if (has_cycle) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
