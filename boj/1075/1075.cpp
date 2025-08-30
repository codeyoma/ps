// https://www.acmicpc.net/problem/1075
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1075/1075
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

    int n, f;
    cin >> n >> f;

    n = (n / 100) * 100;

    for (int i = 0; i < 100; ++i) {
        if ((n + i) % f == 0) {
            if (i < 10) {
                cout << '0';
            }
            cout << i;
            break;
        }
    }
}
