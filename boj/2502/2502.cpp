// https://www.acmicpc.net/problem/2502
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2502/2502
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

    int d, k;
    cin >> d >> k;

    vector<int> dp(d + 1);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= d; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 1;; ++i) {
        if ((k - (dp[d - 2] * i)) % dp[d - 1] == 0) {
            cout << i << "\n";
            cout << (k - (dp[d - 2] * i)) / dp[d - 1];
            break;
        }
    }
}
