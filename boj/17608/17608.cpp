// https://www.acmicpc.net/problem/17608
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/17608/17608
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
    // 새로 들어온 것보다 큰게 나올떄 까지 pop, and then push
    // stack.size() = max view size

    int n;
    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        while (!s.empty() && s.top() <= temp) {
            s.pop();
        }
        s.push(temp);
    }

    cout << s.size();
}
