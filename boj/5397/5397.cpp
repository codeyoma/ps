// https://www.acmicpc.net/problem/5397
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/5397/5397
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
    int n;
    cin >> n;

    while (n--) {
        stack<char> l, r;

        string input;
        cin >> input;

        for (int i = 0; i < input.length(); ++i) {
            switch (input[i]) {
                case '<': {
                    if (!l.empty()) {
                        r.push(l.top());
                        l.pop();
                    }
                    break;
                }
                case '>': {
                    if (!r.empty()) {
                        l.push(r.top());
                        r.pop();
                    }
                    break;
                }
                case '-': {
                    if (!l.empty()) {
                        l.pop();
                    }
                    break;
                }
                default: {
                    l.push(input[i]);
                }
            }
        }

        while (!l.empty()) {
            r.push(l.top());
            l.pop();
        }

        while (!r.empty()) {
            cout << r.top();
            r.pop();
        }
        cout << '\n';
    }
}
