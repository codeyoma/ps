// https://www.acmicpc.net/problem/1526
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1526/1526
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

void dfs(int& best, const int& target, const int& cur) {
    if (cur > target) {
        return;
    }

    best = max(best, cur);
    for (const int& i: { 4, 7 }) {
        dfs(best, target, cur * 10 + i);
    }
}

int main() {
    fast_io();

    //   logic

    int n, origin_n, best = MIN;
    cin >> n;

    dfs(best, n, 0);

    cout << best;
}
