// https://www.acmicpc.net/problem/20301
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/20301/20301
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

#include <deque>
#include <iostream>

int main() {
    //   logic
    int n, k, m;
    cin >> n >> k >> m;

    deque<int> q;

    for (int i = 1; i <= n; ++i) {
        q.push_back(i);
    }

    int  m_count = 0;
    bool direct  = true;

    while (!q.empty()) {
        int k_count = k - 1;

        if (direct) {
            while (k_count--) {
                q.push_back(q.front());
                q.pop_front();
            }
        } else {
            k_count++;
            while (k_count--) {
                q.push_front(q.back());
                q.pop_back();
            }
        }

        cout << q.front() << "\n";
        q.pop_front();
        m_count++;

        if (m_count == m) {
            direct  = !direct;
            m_count = 0;
        }
    }
}
