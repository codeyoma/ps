// https://www.acmicpc.net/problem/31962
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/31962/31962
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
    int n, x;
    cin >> n >> x;

    int answer = MIN;

    while (n--) {
        int start, arrive;

        cin >> start >> arrive;

        if (start + arrive <= x) {
            answer = max(answer, start);
        }
    }

    if (answer == MIN) {
        cout << -1;
    } else {
        cout << answer;
    }
}
