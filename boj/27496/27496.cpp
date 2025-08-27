// https://www.acmicpc.net/problem/27496
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/27496/27496
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

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <queue>

int main() {
    //   logic
    // 큐의 사이즈 - 지속시간
    int    t, d, answer = 0;
    double c = 0;

    cin >> t >> d;
    queue<int> q;

    for (int i = 0; i < t; ++i) {
        int alcohol;
        cin >> alcohol;

        if (q.size() >= d) {
            c -= q.front();
            q.pop();
        }
        c += alcohol;
        q.push(alcohol);

        if (0.129 <= c * 0.001 && c * 0.001 <= 0.138) {
            answer++;
        }
    }

    cout << answer;
}
