// https://www.acmicpc.net/problem/2293
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2293/2293
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

    vector<int> coins(n);
    vector<int> dp(k + 1);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        int coin = coins[i];

        for (int j = coin; j <= k; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[k];
}
