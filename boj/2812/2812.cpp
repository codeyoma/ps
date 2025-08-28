// https://www.acmicpc.net/problem/2812
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2812/2812
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
    int    n, k, count = 0;
    string number;
    cin >> n >> k >> number;

    stack<char> s;

    for (size_t i = 0; i < number.size(); ++i) {
        while (!s.empty() && s.top() < number[i] && count < k) {
            s.pop();
            count++;
        }
        s.push(number[i]);
    }

    while (count < k) {
        s.pop();
        count++;
    }

    stack<char> r_s;

    while (!s.empty()) {
        r_s.push(s.top());
        s.pop();
    }

    while (!r_s.empty()) {
        cout << r_s.top();
        r_s.pop();
    }
}
