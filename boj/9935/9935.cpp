// https://www.acmicpc.net/problem/9935
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/9935/9935
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
#include <string>

int main() {
    //   logic
    string sentence;
    string exp;

    cin >> sentence >> exp;

    deque<char> q;

    for (const char& c: sentence) {
        q.push_back(c);

        if (q.size() >= exp.size()) {
            string last_word(q.end() - exp.size(), q.end());

            if (last_word == exp) {
                q.erase(q.end() - exp.size(), q.end());
            }
        }
    }

    if (q.empty()) {
        cout << "FRULA";
    } else {
        for (const char& c: q) {
            cout << c;
        }
    }
}
