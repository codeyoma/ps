// https://www.acmicpc.net/problem/18352
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

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    fast_io();

    //   logic
    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<int>> adj(n + 1);
    vector<int>         dist(n + 1, _MAX);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dist[x] = 0;
    pq.push({ 0, x });

    while (!pq.empty()) {
        const auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] != cost) {
            continue;
        }

        for (const auto v: adj[u]) {
            int next_cost = cost + 1;

            if (dist[v] > next_cost) {
                dist[v] = next_cost;
                pq.push({ next_cost, v });
            }
        }
    }

    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == k) {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());

    if (answer.empty()) {
        cout << -1;
    } else {
        for (const auto& e: answer) {
            cout << e << "\n";
        }
    }
}
