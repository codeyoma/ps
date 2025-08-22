// https://www.acmicpc.net/problem/11365
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11365/11365
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

#include <algorithm>
#include <iostream>
#include <string>

int main() {
    //   logic
    string input;

    while (getline(cin, input)) {
        if (input == "END") {
            break;
        }
        reverse(input.begin(), input.end());
        cout << input << '\n';
    }
}
