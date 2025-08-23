// https://www.acmicpc.net/problem/12605
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/12605/12605
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
    string n;
    getline(cin, n);

    int origin_n = stoi(n);

    for (int i = 1; i <= origin_n; ++i) {
        stack<string> s;
        string        line;
        getline(cin, line);

        string::size_type pos = 0;

        while ((pos = line.find(' ', pos)) != string::npos) {
            string word = line.substr(0, pos);
            s.push(word);
            line = line.substr(pos + 1);
            pos  = 0;
        }
        s.push(line);

        cout << "Case #" << i << ":";
        while (!s.empty()) {
            cout << " " << s.top();
            s.pop();
        }
        cout << "\n";
    }
}
