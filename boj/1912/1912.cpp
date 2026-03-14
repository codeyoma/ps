// https://www.acmicpc.net/problem/1912
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1912/1912
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
    // 1차원 dp
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> dp(n);
    dp[0]      = v[0];
    int answer = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i]  = max(dp[i - 1] + v[i], v[i]);
        answer = max(dp[i], answer);
    }

    cout << answer;

    // solution 2
    // 2차원 dp

    // solution 3
    // 카데인 알고리즘 (엄밀히 말하자면 dp가 아님) - overlapping subproblem, optimal substructure
    // 계속 더한 값이, 현재 값보다 작다면 포기하고 현재값부터 다시 더하기

    // int answer  = MIN;
    // int cur_max = 0;

    // while (n--) {
    //     int temp;
    //     cin >> temp;

    //     cur_max = max(cur_max + temp, temp);
    //     answer  = max(answer, cur_max);
    // }

    // cout << answer;
}
