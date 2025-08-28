// https://www.acmicpc.net/problem/2504
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2504/2504
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

bool check_bracket(const char* c) {
    const char* check = "[]()";

    while (*check) {
        if (*check == *c) {
            return false;
        }
        check++;
    }

    return true;
}

int main() {
    //   logic
    string statement;
    cin >> statement;
    stack<string> s;

    // 닫히면, 열리는거 나올때까지 팝하기
    // - 숫자라면 더하기
    // - 닫히면, 이전 숫자 더한거 * bias, 스택에 push
    // 스택에 남은 숫자들 더하고 출력
    for (const char c: statement) {
        if (c == ')' || c == ']') {
            int    temp = 0;
            string open = (c == ')') ? "(" : "[";

            while (!s.empty() && s.top() != open) {
                const string& top = s.top();

                if (top == "(" || top == ")" || top == "[" || top == "]") {
                    cout << 0;
                    return 0;
                }
                LOG << top << "\n";
                temp += stoi(top);
                s.pop();
            }

            if (s.empty() || s.top() != open) {
                cout << 0;
                return 0;
            }

            s.pop();

            if (temp == 0) {
                temp = 1;
            }
            s.push(to_string(temp * ((c == ')') ? 2 : 3)));
            LOG << to_string(temp * ((c == ')') ? 2 : 3)) << "\n";
        } else {
            s.push(string(1, c));
        }
    }

    int answer = 0;
    while (!s.empty()) {
        const string& top = s.top();
        if (top == "(" || top == "[" || top == ")" || top == "]") {
            cout << 0;
            return 0;
        }
        answer += stoi(top);
        s.pop();
    }

    cout << answer;
}
