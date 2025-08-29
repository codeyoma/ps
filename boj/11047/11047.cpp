// https://www.acmicpc.net/problem/11047
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11047/11047
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
    int n, k;

    cin >> n >> k;
    vector<int> w(n);

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int cnt           = 0;
    int last_coin_pos = n - 1;

    while (k > 0 && last_coin_pos >= 0) {
        if ((k / w[last_coin_pos]) >= 1) {
            cnt += (k / w[last_coin_pos]);
            k %= w[last_coin_pos];
        }
        last_coin_pos--;
    }
    cout << cnt;
}

void _old_solution() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int count = 0;
    int pos   = n - 1;
    while (k || pos >= 0) {
        if ((k / coins[pos]) >= 1) {
            count += (k / coins[pos]);
            k %= coins[pos];
        }
        pos--;
    }

    cout << count;
}