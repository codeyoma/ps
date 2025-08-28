// https://www.acmicpc.net/problem/27497
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/27497/27497
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

typedef enum status {
    LEFT,
    RIGHT
} Status;

int main() {
    //   logic
    int n;
    cin >> n;
    deque<char>   q;
    deque<Status> s;

    while (n--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            char c;
            cin >> c;
            q.push_back(c);
            s.push_back(RIGHT);
        } else if (cmd == 2) {
            char c;
            cin >> c;
            q.push_front(c);
            s.push_back(LEFT);
        } else {
            if (!q.empty() && !s.empty()) {
                Status before_cmd = s.back();
                s.pop_back();

                if (before_cmd == RIGHT) {
                    q.pop_back();
                } else {
                    q.pop_front();
                }
            }
        }
    }

    if (q.empty()) {
        cout << 0;
    } else {
        for (const auto& c: q) {
            cout << c;
        }
    }
}
