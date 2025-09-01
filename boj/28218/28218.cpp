// https://www.acmicpc.net/problem/28218
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/28218/28218
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

int main() {
    fast_io();

    //   logic

    int n, m, k;
    cin >> n >> m >> k;

    vector<string>       map(n);
    vector<vector<bool>> dp(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> map[i];
    }

    // grundy number
    // winning, losing state
    // 이전 게임에서 주변에 한게임이라도 졌다면 지금은 이기는게 가능
    {
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (map[r][c] == '#') {
                    continue;
                }
                bool is_win = false;

                if (r + 1 < n && map[r + 1][c] == '.' && dp[r + 1][c] == false) {
                    is_win = true;
                }

                if (c + 1 < m && map[r][c + 1] == '.' && dp[r][c + 1] == false) {
                    is_win = true;
                }

                for (int d = 1; d <= k; ++d) {
                    if (r + d < n && c + d < m) {
                        if (map[r + d][c + d] == '.' && dp[r + d][c + d] == false) {
                            is_win = true;
                        }
                    } else {
                        break;
                    }
                }

                dp[r][c] = is_win;
            }
        }
    }

    for (const auto& r: dp) {
        for (const auto& c: r) {
            LOG << c << " ";
        }
        LOG << "\n";
    }

    {
        int q;
        cin >> q;

        while (q--) {
            int x, y;
            cin >> x >> y;

            if (dp[x - 1][y - 1]) {
                cout << "First\n";
            } else {
                cout << "Second\n";
            }
        }
    }
}
