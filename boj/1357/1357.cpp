// https://www.acmicpc.net/problem/1357
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1357/1357
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

int rev(int n) {
    int r = 0;
    while (n > 0) {
        r = (r * 10) + n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    fast_io();

    //   logic
    int x, y;
    cin >> x >> y;

    cout << rev(rev(x) + rev(y));
}
