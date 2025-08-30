// https://www.acmicpc.net/problem/2563
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2563/2563
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
    vector<vector<bool>> v(101, vector<bool>(101, false));

    int n;
    cin >> n;

    while (n--) {
        int s_x, s_y;
        cin >> s_x >> s_y;

        for (int x = s_x; x < s_x + 10; ++x) {
            for (int y = s_y; y < s_y + 10; ++y) {
                v[x][y] = true;
            }
        }
    }

    int answer = 0;
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            if (v[x][y]) {
                answer++;
            }
        }
    }
    cout << answer;
}
