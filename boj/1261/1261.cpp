// https://www.acmicpc.net/problem/1261
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

typedef struct Node {
    int x;
    int y;
    int cost;

    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
} Node;

int main() {
    fast_io();

    //   logic

    int n, m;
    cin >> n >> m;

    vector<string>      map(m);
    vector<vector<int>> dist(m, vector<int>(n, _MAX));

    for (int i = 0; i < m; ++i) {
        cin >> map[i];
    }

    priority_queue<Node> q;

    q.push({ 0, 0, 0 });
    dist[0][0] = 0;

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto [x, y, cost] = q.top();
        // LOG << x << " " << y << " : " << cost << '\n';
        q.pop();

        if (dist[x][y] < cost) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            int new_cost = cost + (map[nx][ny] == '1');

            if (new_cost < dist[nx][ny]) {
                dist[nx][ny] = new_cost;
                q.push({ nx, ny, new_cost });
            }
        }
    }

    cout << dist[m - 1][n - 1];
}
