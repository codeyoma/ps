// https://www.acmicpc.net/problem/1854
#include <iostream>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int cost;
    int v;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    fast_io();

    //   logic

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>>            dist(n + 1);

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    for (int i = 0; i < m; ++i) {
        int s, d, w;
        cin >> s >> d >> w;

        adj[s].push_back({ d, w });
    }

    dist[1].push_back(0);
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        const auto [cost, u] = pq.top();
        auto& du             = dist[u];
        pq.pop();

        if (du.size() == k && du.front() < cost) {
            continue;
        }

        for (const auto& [next, w]: adj[u]) {
            int   next_cost = w + cost;
            auto& dv        = dist[next];

            if (dv.size() < k) {
                dv.push_back(next_cost);
                push_heap(dv.begin(), dv.end());
                pq.push({ next_cost, next });
            } else if (dv.front() > next_cost) {
                pop_heap(dv.begin(), dv.end());
                dv.back() = next_cost;
                push_heap(dv.begin(), dv.end());
                pq.push({ next_cost, next });
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i].size() < k) {
            cout << "-1\n";
        } else {
            cout << dist[i].front() << "\n";
        }
    }
}
