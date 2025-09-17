// https://www.acmicpc.net/problem/1738
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

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <vector>

struct node {
    int u;
    int v;
    int w;
};

int main() {
    fast_io();

    //   logic
    int n, m, start = 0;
    cin >> n >> m;

    vector<node> adj(m);
    vector<int>  dist(n, MIN);
    vector<int>  predecessor(n, -1);
    dist[start] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[i] = { u - 1, v - 1, w };
    }

    for (int i = 0; i < n; ++i) {
        for (const node& e: adj) {
            if (dist[e.u] != MIN && dist[e.v] < dist[e.u] + e.w) {
                // if (i == n - 1) {
                //     cout << -1;
                //     return 0;
                // }
                dist[e.v]        = dist[e.u] + e.w;
                predecessor[e.v] = e.u;
                if (i == n - 1) {
                    predecessor[e.v] = -2;
                }
            }
        }
    }

    if (dist[n - 1] == MAX) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int target = n - 1; target != -1; target = predecessor[target]) {
        path.push_back(target + 1);
    }

    reverse(path.begin(), path.end());

    for (const auto& i: path) {
        cout << i << " ";
    }

    return 0;
}
