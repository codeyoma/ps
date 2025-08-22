// https://www.acmicpc.net/problem/1225
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1225/1225
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
#include <string>

int main() {
    //   logic
    string a, b;
    cin >> a >> b;

    long long answer = 0;

    for (int i = 0; i < a.length(); ++i) {
        for (int j = 0; j < b.length(); ++j) {
            answer += (a[i] - '0') * (b[j] - '0');
        }
    }
    cout << answer;
}
