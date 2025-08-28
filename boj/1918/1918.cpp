// https://www.acmicpc.net/problem/1918
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1918/1918
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
    string statement;
    cin >> statement;

    stack<char> s;
    bool        check_cross_over = false;

    // 스택에 연산자 우선순위가 높은거 미리 출력, 낮은거는 나중에
    // 알파벳은 바로 출력

    // pair로 우선순위도 같이 기재하여 스택에 넣기?
    for (const char c: statement) {
    }
}
