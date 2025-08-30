// https://www.acmicpc.net/problem/2775
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2775/2775
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
    // 1  2  3  4   5   6
    // 1  3  6 10  15  21
    // 1  4 10 20  35  56
    // 1  5 15 35  70 126
    // 1  6 21 56 126 252

    vector<vector<int>> dp(15, vector<int>(15));

    for (int i = 1; i < 15; ++i) {
        dp[0][i] = i;
    }

    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }
}
