// https://www.acmicpc.net/problem/1110
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1110/1110
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
    int n;
    cin >> n;

    int origin_n = n;
    int count    = 0;

    while (true) {
        int l_r, r_r;

        l_r = n % 10;
        r_r = (n / 10 + n % 10) % 10;

        n = l_r * 10 + r_r;
        count++;

        if (n == origin_n) {
            break;
        }
    }

    cout << count;
}
