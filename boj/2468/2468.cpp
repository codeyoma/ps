// https://www.acmicpc.net/problem/2468
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
#include <stack>
#include <vector>

int main() {
    fast_io();
    int n, max_height = 0;

    cin >> n;

    vector<vector<int>> city(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> city[i][j];
            if (max_height < city[i][j]) {
                max_height = city[i][j];
            }
        }
    }

    int dx[] = { 0, -1, 0, 1 };
    int dy[] = { 1, 0, -1, 0 };

    int answer = 0;

    for (int t = 0; t < max_height; ++t) {
        vector<vector<bool>> visit(n, vector<bool>(n, false));

        stack<pair<int, int>> dfs;
        int                   cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j]) {
                    continue;
                }

                if (city[i][j] <= t) {
                    continue;
                }

                dfs.push({ i, j });
                visit[i][j] = true;

                while (!dfs.empty()) {
                    const auto [x, y] = dfs.top();
                    dfs.pop();

                    for (int c = 0; c < 4; ++c) {
                        int nx = dx[c] + x;
                        int ny = dy[c] + y;

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }

                        if (visit[nx][ny] || city[nx][ny] <= t) {
                            continue;
                        }

                        visit[nx][ny] = true;

                        dfs.push({ nx, ny });
                    }
                }

                cnt++;
            }
        }

        if (cnt > answer) {
            answer = cnt;
        }
    }

    cout << answer;

    //   logic
}
