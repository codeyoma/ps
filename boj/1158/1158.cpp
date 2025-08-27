// https://www.acmicpc.net/problem/1158
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1158/1158
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
    int n, t;
    cin >> n >> t;

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) {
        for (int i = 1; i < t; ++i) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (q.size() >= 1) {
            cout << ", ";
        }
    }
    cout << ">";
}
