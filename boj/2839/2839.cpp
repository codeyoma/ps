// https://www.acmicpc.net/problem/2839
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

int _solve_greedy() {
    int n, count = 0;

    cin >> n;

    while (n >= 0) {
        if (n % 5 == 0) {
            cout << count + (n / 5);
            return 0;
        }
        n -= 3;
        count++;
    }
    cout << -1;
}

int main() {
    //   logic
    int n;
    cin >> n;
    vector<int> dp(n + 1, MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i - 3 >= 0) {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        if (i - 5 >= 0) {
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }
    if (dp[n] == MAX) {
        cout << -1;
    } else {
        cout << dp[n];
    }
}
