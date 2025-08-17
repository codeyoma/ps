// https://www.acmicpc.net/problem/18111
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

//--------------------------------------------------------------------------------------------------
#define MAX (1234567891)
#define MIN (-1234567891)
#include <iostream>
#include <vector>

int main() {
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    int answer = MAX;
    int height = 256;

    for (int test = 0; test <= 256; ++test) {
        int time   = 0;
        int temp_b = b;

        for (const auto& y: map) {
            for (const auto& x: y) {
                int gap = abs(test - x);

                if (test >= x) {
                    time += gap;
                    temp_b -= gap;
                } else {
                    time += (2 * gap);
                    temp_b += gap;
                }
            }
        }

        if (temp_b >= 0 && time <= answer) {
            answer = time;
            height = test;
        }
    }
    LOG << answer;
    cout << answer << " " << height;
    return 0;
}
