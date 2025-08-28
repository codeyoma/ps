// https://www.acmicpc.net/problem/2346
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2346/2346
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
    int n;
    cin >> n;

    deque<pair<int, int>> q;

    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        q.push_back({ i, temp });
    }

    // 3 2 1 - 3 -1

    while (!q.empty()) {
        pair<int, int> balloon = q.front();
        q.pop_front();
        cout << balloon.first << " ";

        if (q.empty()) {
            break;
        }
        if (balloon.second > 0) {
            for (int i = 1; i < balloon.second; ++i) {
                q.push_back(q.front());
                q.pop_front();
            }
        } else {
            for (int i = -1; i >= balloon.second; --i) {
                q.push_front(q.back());
                q.pop_back();
            }
        }
    }
}
