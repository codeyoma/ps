// https://www.acmicpc.net/problem/10821
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10821/10821
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
    string input;
    cin >> input;

    int answer = 0;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == ',') {
            answer++;
        }
    }
    cout << answer + 1;
}
