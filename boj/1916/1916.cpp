// https://www.acmicpc.net/problem/1916
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

int main() {
    fast_io();

    //   logic

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int>                    dist(n + 1, _MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    for (int i = 0; i < m; ++i) {
        int s, d, w;
        cin >> s >> d >> w;
        adj[s].push_back({ d, w });
    }
    int s, d;
    cin >> s >> d;

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        const auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] != cost) {
            continue;
        }

        for (const auto& [v, w]: adj[u]) {
            int next_w = cost + w;

            if (dist[v] > next_w) {
                dist[v] = next_w;
                pq.push({ next_w, v });
            }
        }
    }

    cout << dist[d];
}
