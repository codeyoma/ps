// https://www.acmicpc.net/problem/3986
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/3986/3986
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
    int n, answer = 0;
    cin >> n;

    while (n--) {
        stack<char> s;
        string      word;
        cin >> word;

        for (int i = 0; i < word.length(); ++i) {
            if (!s.empty() && s.top() == word[i]) {
                s.pop();
            } else {
                s.push(word[i]);
            }
        }
        if (s.empty()) {
            answer++;
        }
    }

    cout << answer;
}
