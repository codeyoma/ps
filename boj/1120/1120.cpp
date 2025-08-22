// https://www.acmicpc.net/problem/1120
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1120/1120
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

    int answer = MAX;

    for (int b_i = 0; b_i <= b.length() - a.length(); ++b_i) {
        int unmatch_count = 0;

        for (int a_i = 0; a_i < a.length(); ++a_i) {
            if (a[a_i] != b[b_i + a_i]) {
                unmatch_count++;
            }
        }

        answer = min(answer, unmatch_count);
    }

    cout << answer;
}
