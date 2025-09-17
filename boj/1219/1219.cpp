// https://www.acmicpc.net/problem/1219
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
/*
#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <queue>
#include <vector>

struct node {
    int       to;
    long long cost;
};

int main() {
    fast_io();

    //   logic
    int n, s, e, m;

    cin >> n >> s >> e >> m;

    vector<vector<node>> adj(n);
    vector<long long>    value(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v, w });
    }

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    vector<long long> dist(n, MIN);
    vector<bool>      visit(n, false);
    vector<int>       cycle;
    dist[s]  = value[s];
    visit[s] = true;

    bool has_infinity_value = false;

    { // bellman-ford
        for (int i = 0; i < n; ++i) {
            bool has_update = false;

            for (int u = 0; u < n; ++u) {
                if (dist[u] == MIN) {
                    continue;
                }

                for (const node& edge: adj[u]) {
                    if (dist[edge.to] < (dist[u] - edge.cost + value[edge.to])) {
                        dist[edge.to] = dist[u] - edge.cost + value[edge.to];
                        has_update    = true;

                        if (i == n - 1) {
                            cycle.push_back(edge.to);
                        }

                        visit[edge.to] = true;
                    }
                }
            }

            if (has_update == false) {
                break;
            }
        }
    }

    { // bfs
        while (!cycle.empty()) {
            queue<int>   bfs;
            vector<bool> v(n);

            bfs.push(cycle.back());
            cycle.pop_back();

            while (!bfs.empty()) {
                int current = bfs.front();
                bfs.pop();

                if (v[current]) {
                    continue;
                }

                v[current] = true;

                for (const auto& i: adj[current]) {
                    if (v[i.to] == false) {
                        bfs.push(i.to);
                    }
                }
            }
            if (v[e]) {
                has_infinity_value = true;
                break;
            }
        }
    }

    if (dist[e] == MIN) {
        cout << "gg";
    } else if (has_infinity_value) {
        cout << "Gee";
    } else {
        cout << dist[e];
    }
}
*/

/*
#include <iostream>
#include <vector>
#define INF 1234567891

using namespace std;
int                    n, s_, e_, s, e, m;
long long              sp, ep, p;
long long              N[55];
long long              C[55];
long long              E[55][55];
vector<pair<int, int>> V;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> s_ >> e_ >> m;

    for (int i = 0; i < n; i++) {
        N[i] = -INF;

        for (int j = 0; j < n; j++) {
            E[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> sp >> ep >> p;
        V.push_back({ sp, ep });
        E[sp][ep] = min(E[sp][ep], p);
    }

    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    N[s_] = C[s_];

    for (int i = 0; i < n - 1; i++) {
        for (const auto& [s, e]: V) {
            if (N[s] == -INF || E[s][e] == INF) {
                continue;
            }

            if (N[e] < (N[s] - E[s][e] + C[e])) {
                N[e] = N[s] - E[s][e] + C[e];

                if (i == n - 1) {
                }
            }
        }
    }

    if (N[e_] == -INF) {
        cout << "gg";
        return 0;
    }

    long long answer = N[e_];
    for (int i = 0; i < n * 2; i++) {
        for (const auto& [s, e]: V) {
            if (N[s] == -INF || E[s][e] == INF) {
                continue;
            }

            if (N[e] < (N[s] - E[s][e] + C[e])) {
                N[e] = N[s] - E[s][e] + C[e];
                if (e == e_) {
                    cout << "Gee";
                    return 0;
                }
            }
        }
    }
    cout << answer;
}
*/
#include <iostream>
#include <vector>
#define INF 1234567891

using namespace std;

struct node {
    long long next;
    long long w;
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, s_, e_, m;

    cin >> n >> s_ >> e_ >> m;

    vector<long long>    N(n, -INF);
    vector<long long>    C(n);
    vector<vector<node>> V(n);

    for (int i = 0; i < m; i++) {
        long long sp, ep, p;
        cin >> sp >> ep >> p;

        V[sp].push_back({ ep, p });
    }

    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    N[s_] = C[s_];

    for (int i = 0; i < n; i++) {
        bool has_update = false;

        for (int s = 0; s < n; ++s) {
            if (N[s] == -INF) {
                continue;
            }

            for (const auto& [next, w]: V[s]) {
                if (N[next] < (N[s] - w + C[next])) {
                    N[next]    = N[s] - w + C[next];
                    has_update = true;
                }
            }
        }

        if (has_update == false) {
            break;
        }
    }

    if (N[e_] == -INF) {
        cout << "gg";
        return 0;
    }

    long long answer = N[e_];
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < n; ++s) {
            if (N[s] == -INF) {
                continue;
            }

            for (const auto& [next, w]: V[s]) {
                if (N[next] < (N[s] - w + C[next])) {
                    N[next] = N[s] - w + C[next];
                    if (next == e_) {
                        cout << "Gee";
                        return 0;
                    }
                }
            }
        }
    }
    cout << answer;
}