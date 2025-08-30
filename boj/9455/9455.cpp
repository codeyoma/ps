// https://www.acmicpc.net/problem/9455
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/9455/9455
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
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<bool>> v(m, vector<bool>(n));

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                int temp;
                cin >> temp;
                v[x][y] = temp;
            }
        }

        int answer = 0;
        for (int x = m - 1; x >= 0; --x) {
            for (int y = 0; y < n; ++y) {
                if (v[x][y]) {
                    continue;
                }

                for (int r = x - 1; r >= 0; --r) {
                    if (v[r][y]) {
                        v[r][y] = false;
                        v[x][y] = true;
                        answer += x - r;
                        break;
                    }
                }
            }
        }

        cout << answer << "\n";
    }
}
