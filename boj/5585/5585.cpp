// https://www.acmicpc.net/problem/5585
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/5585/5585
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
    int pay;
    cin >> pay;

    int change = 1000 - pay;

    vector<int> coin = {
        500,
        100,
        50,
        10,
        5,
        1
    };

    int count = 0;

    for (int i = 0; i < static_cast<int>(coin.size()); ++i) {
        count += change / coin[i];
        change %= coin[i];
    }

    cout << count;
}

void _old_solution() {
    int pay;
    cin >> pay;

    int change = 1000 - pay;

    vector<int> coin = {
        500,
        100,
        50,
        10,
        5,
        1
    };

    int coin_pos = 0;
    int count    = 0;

    while (change > 0 || coin_pos < static_cast<int>(coin.size())) {
        if (change / coin[coin_pos] > 0) {
            count += change / coin[coin_pos];
            change %= coin[coin_pos];
        }
        coin_pos++;
    }

    cout << count;
}