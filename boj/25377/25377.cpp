// https://www.acmicpc.net/problem/25377
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/25377/25377
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
    int n, answer = MAX;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        if (a <= b) {
            answer = min(b, answer);
        }
    }

    if (answer == MAX) {
        cout << -1;
    } else {
        cout << answer;
    }
}
