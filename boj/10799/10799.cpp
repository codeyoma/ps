// https://www.acmicpc.net/problem/10799
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10799/10799
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

int main() {
    //   logic
    string      input;
    stack<char> s;

    cin >> input;

    // () 은 레이저
    // 레이저면 스택 사이즈만큼 +
    // 레이저다? flag on
    // 닫히는데) 이전에 레이저 있었다면 막대기 종료
    // 닫히면 + 1
    // 닫히지 않는다? -> flag off

    bool laser_occured = false;
    int  answer        = 0;
    for (int i = 0; i < input.length(); ++i) {
        if (!s.empty() && !laser_occured && input[i] == ')' && s.top() == '(') { // laser
            s.pop();
            answer += s.size();
            laser_occured = true;

        } else if (!s.empty() && laser_occured && input[i] == ')' && s.top() == '(') { // close
            s.pop();
            answer++;
        } else {
            laser_occured = false;
            s.push(input[i]);
        }
    }

    cout << answer;
}
