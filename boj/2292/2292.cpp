// https://www.acmicpc.net/problem/2292
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2292/2292
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

#include <cmath>
#include <iostream>

int main() {
    fast_io();

    //   logic
    int n;
    cin >> n;

    int start_value = 1;
    int bias        = 5;

    // solution 1
    // 시뮬레이션
    {
        int cycle = 1;
        while (n > 1) {
            n -= (6 * cycle);
            cycle++;
        }
        cout << cycle;
    }

    // solution 2
    // 등차 수열의 합 -> 부등식 -> 근의 공식
    // b < c <= a
    // 1, 6, 12, 18, 24, 30, 36, 42 ...
    // 1, 7, 19, 37, 61, 91, 127, 169 ...
    // 6(k - 1)
    // 6 * ((k - 1)k) / 2
    // 3k(k - 1) + 1

    // n <= 3k(k - 1) + 1
    // 3k^2 - 3k + (1 - n)
    // (3 + /sqrt(9 - 4 * 3 * (1 - n))) / 2 * 3
    // (3 + \sqrt(12n - 3)) / 6

    // {
    //     if (n == 1) {
    //         cout << 1;
    //     } else {
    //         cout << static_cast<int>(ceil((3 + sqrt(12.0 * n - 3)) / 6.0));
    //     }
    // }
}
