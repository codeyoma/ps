// https://www.acmicpc.net/problem/1100
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1100/1100
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
    int  n      = 8;
    int  answer = 0;
    bool flip   = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char current;
            cin >> current;

            if (flip) {
                if (j & 1 && current == 'F') {
                    answer++;
                }
            } else {
                if (!(j & 1) && current == 'F') {
                    answer++;
                }
            }
        }
        flip = !flip;
    }

    cout << answer;
}
