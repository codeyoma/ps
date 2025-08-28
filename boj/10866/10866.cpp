// https://www.acmicpc.net/problem/10866
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10866/10866
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
    deque<int> q;

    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            cin >> cmd;
            q.push_front(stoi(cmd));
        } else if (cmd == "push_back") {
            cin >> cmd;
            q.push_back(stoi(cmd));
        } else if (cmd == "pop_front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << "\n";
                q.pop_back();
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "empty") {
            cout << (q.empty() ? 1 : 0) << "\n";
        } else if (cmd == "front") {
            cout << (q.empty() ? -1 : q.front()) << "\n";
        } else if (cmd == "back") {
            cout << (q.empty() ? -1 : q.back()) << "\n";
        }
    }
}
