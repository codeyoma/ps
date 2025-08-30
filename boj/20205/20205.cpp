// https://www.acmicpc.net/problem/20205
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/20205/20205
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
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> up_sampling(n * k, vector<bool>(n * k, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int dot;
            cin >> dot;

            for (int x = i * k; x < i * k + k; ++x) {
                for (int y = j * k; y < j * k + k; ++y) {
                    up_sampling[x][y] = dot;
                }
            }
        }
    }

    for (int i = 0; i < n * k; ++i) {
        for (int j = 0; j < n * k; ++j) {
            cout << up_sampling[i][j] << " ";
        }
        cout << "\n";
    }
}
