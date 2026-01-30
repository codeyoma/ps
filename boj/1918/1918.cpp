#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <string>

int main() {
    FAST_IO

    //   logic
    //   logic
    string statement;
    cin >> statement;

    stack<char> s;

    // 스택에 연산자 우선순위가 높은거 미리 출력, 낮은거는 나중에
    // 알파벳은 바로 출력

    // pair로 우선순위도 같이 기재하여 스택에 넣기?
    for (const char c: statement) {
        switch (c) {
            case '(': {
                s.push(c);
                break;
            }
            case ')': {
                while (!s.empty() && s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                break;
            }
            case '*':
            case '/': {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    cout << s.top();
                    s.pop();
                }

                s.push(c);
                break;
            }
            case '+':
            case '-': {
                while (!s.empty() && s.top() != '(') {
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
                break;
            }
            default: {
                cout << c;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
