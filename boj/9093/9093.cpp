// https://www.acmicpc.net/problem/9093
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/9093/9093
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
// #include <deque>
#include <string>

int main() {
    //   logic
    // string s_n;
    // getline(cin, s_n);
    // int n = stoi(s_n);
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        queue<string> q;
        string        line;
        getline(cin, line);
        string::size_type pos = 0;

        while ((pos = line.find(" ", pos)) != string::npos) {
            q.push(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos  = 0;
        }
        if (!line.empty()) {
            q.push(line);
        }

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            for (string::reverse_iterator it = word.rbegin(); it != word.rend(); ++it) {
                cout << *it;
            }
            cout << " ";
        }
        cout << "\n";
    }
}
