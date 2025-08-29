// https://www.acmicpc.net/problem/1085
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1085/1085
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

    int x, y, w, h, answer = MAX;
    cin >> x >> y >> w >> h;

    answer = min(answer, x - 0);
    answer = min(answer, w - x);
    answer = min(answer, y - 0);
    answer = min(answer, h - y);

    cout << answer;
}
