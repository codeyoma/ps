// https://www.acmicpc.net/problem/1475
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1475/1475
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
#include <vector>

int main() {
    fast_io();

    //   logic
    int n;
    cin >> n;

    vector<int> v(10);

    while (n > 0) {
        v[n % 10]++;
        n /= 10;
    }

    v[6] = (v[6] + v[9] + 1) / 2;

    int answer = MIN;

    // 9 제외
    for (int i = 0; i < 9; ++i) {
        answer = max(answer, v[i]);
    }
    cout << answer;
}
