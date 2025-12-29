// https://www.acmicpc.net/problem/1504
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
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>

vector<ll> dijkstra(const int& n, const vector<vector<pair<int, int>>>& adj, int start) {
    vector<ll> dist(n + 1, _MAX);
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>>
        pq;
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        const auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] != cost) {
            continue;
        }

        for (const auto [v, w]: adj[u]) {
            int next_w = w + cost;

            if (dist[v] > next_w) {
                dist[v] = next_w;
                pq.push({ next_w, v });
            }
        }
    }

    return dist;
}

int main() {
    fast_io();

    //   logic

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<ll> s_dist  = dijkstra(n, adj, 1);
    vector<ll> v1_dist = dijkstra(n, adj, v1);
    vector<ll> v2_dist = dijkstra(n, adj, v2);

    ll path1, path2;

    path1 = s_dist[v1] + v1_dist[v2] + v2_dist[n];
    path2 = s_dist[v2] + v2_dist[v1] + v1_dist[n];

    if (path1 >= _MAX && path2 >= _MAX) {
        cout << -1;
    } else if (path1 < path2) {
        cout << path1;
    } else {
        cout << path2;
    }
}
