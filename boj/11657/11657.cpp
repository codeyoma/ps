// https://www.acmicpc.net/problem/11657
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
#include <vector>

typedef struct Edge {
    int start;
    int to;
    int cost;
} Edge;

int main() {
    fast_io();

    //   logic
    int n, m;
    cin >> n >> m;

    // 모든 간선을 탐색 해야하기에, 일차원으로 저장함
    // 다익스트라 처럼 굳이  2차원으로 인접 리스트 관리 안해도 됨
    vector<Edge> adj;
    vector<ll>   dist(n + 1, _MAX);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        adj.push_back({ a, b, c });
    }

    bool check_cycle = false;
    dist[1]          = 0;

    // bellman-ford algorithm
    {
        for (int v = 0; v < n; ++v) {
            for (const auto& e: adj) {
                const auto [start, to, cost] = e;

                // 시작이 지점이 불가능이면 relaxtion 안함
                if (dist[start] == _MAX) {
                    continue;
                }

                if (dist[to] > dist[start] + cost) {
                    dist[to] = dist[start] + cost;

                    // 마지막 회차에서 업데이트가 발생했다면
                    if (v == (n - 1)) {
                        check_cycle = true;
                        break;
                    }
                }
            }
        }
    }

    if (check_cycle) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= n; ++i) {
            if (dist[i] == _MAX) {
                cout << -1 << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }
}
