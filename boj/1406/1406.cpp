// https://www.acmicpc.net/problem/1406
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1406/1406
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
#include <stack>
#include <string>

int main() {
    //   logic
    string text;
    cin >> text;
    stack<char> a, b;

    for (int i = 0; i < text.length(); ++i) {
        a.push(text[i]);
    }

    int n;
    cin >> n;

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'P') {
            cin >> cmd;
            a.push(cmd);
        } else if (cmd == 'L') {
            if (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        } else if (cmd == 'D') {
            if (!b.empty()) {
                a.push(b.top());
                b.pop();
            }
        } else if (cmd == 'B') {
            if (!a.empty()) {
                a.pop();
            }
        }
    }

    while (!a.empty()) {
        b.push(a.top());
        a.pop();
    }

    while (!b.empty()) {
        cout << b.top();
        b.pop();
    }
}
