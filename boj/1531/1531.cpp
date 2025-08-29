// https://www.acmicpc.net/problem/1531
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1531/1531
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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(101, vector<int>(101, 0));

    while (n--) {
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;

        for (int x = s_x; x <= e_x; ++x) {
            for (int y = s_y; y <= e_y; ++y) {
                v[x][y]++;
            }
        }
    }

    int answer = 0;

    for (const auto& r: v) {
        for (const auto& c: r) {
            if (c > m) {
                answer++;
            }
        }
    }

    cout << answer;
}
