// https://www.acmicpc.net/problem/2669
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2669/2669
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

    // solution 1
    // set으로 1개씩 분할된 좌표 넣기
    // -> 카운트

    // solution 2
    // 2차원 배열로 brutal forece

    int                  n = 4;
    vector<vector<bool>> v(101, vector<bool>(101, false));

    while (n--) {
        int s_x, s_y, e_x, e_y;
        cin >> s_x >> s_y >> e_x >> e_y;

        for (int x = s_x; x < e_x; ++x) {
            for (int y = s_y; y < e_y; ++y) {
                v[x][y] = true;
            }
        }
    }

    int answer = 0;
    for (const auto& r: v) {
        for (const auto& c: r) {
            if (c) {
                answer++;
            }
        }
    }
    cout << answer;
}
