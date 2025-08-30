// https://www.acmicpc.net/problem/32068
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/32068/32068
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

int main() {
    fast_io();

    //   logic
    int t;
    cin >> t;

    while (t--) {
        int l, r, s;
        cin >> l >> r >> s;

        bool is_close_with_right = true;

        if (r - s > s - l) {
            is_close_with_right = false;
        }

        if (is_close_with_right) {
            cout << (r - s) * 2 << "\n";
        } else {
            cout << (s - l) * 2 + 1 << "\n";
        }

        // 완전 시뮬레이션은 time over
        // {
        //     long long l, r, s, count = 1;
        //     cin >> l >> r >> s;

        //     long long bias = 1;
        //     while (true) {
        //         if (s == r || s == l) {
        //             cout << count << "\n";
        //             break;
        //         }

        //         s += bias;
        //         count++;

        //         if (bias < 0) {
        //             bias *= -1;
        //             bias++;
        //         } else {
        //             bias++;
        //             bias *= -1;
        //         }
        //     }
        // }
    }
}
