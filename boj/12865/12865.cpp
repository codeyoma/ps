// https://www.acmicpc.net/problem/12865
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/12865/12865
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

struct item {
    int value;
    int weight;
};

int main() {
    fast_io();

    //   logic
    int n, k;
    cin >> n >> k;

    vector<item> items(n + 1);

    // 0행, 0열 필요
    // 이전 배낭의 무게에 현재 무게를 계산하기위해
    for (int i = 1; i <= n; ++i) {
        int w, v;
        cin >> w >> v;

        items[i] = { v, w };
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // i = current item
    // w = current targe weight
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= k; ++w) {
            if (items[i].weight > w) {
                // 현재 아이템의 무게 공간이 안나온다면, 이전 아이템의 무게일떄의 값 계승
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(
                    // 이전 아이템의 무게
                    dp[i - 1][w],
                    // 이전 무게에서 현재 아이템의 가능한 무게 공간을 만들고, 그 때의 가치에서, 현재 아이템 가치 더하기
                    dp[i - 1][w - items[i].weight] + items[i].value);
            }
        }
    }

    cout << dp[n][k];
}
