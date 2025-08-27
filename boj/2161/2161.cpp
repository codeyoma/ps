// https://www.acmicpc.net/problem/2161
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2161/2161
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
    int n;
    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        if (q.size() == 0) {
            break;
        }
        q.push(q.front());
        q.pop();
    }
}
