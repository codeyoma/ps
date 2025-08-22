// https://www.acmicpc.net/problem/2495
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2495/2495
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
    int n = 3;
    while (n--) {
        string input;
        cin >> input;

        int max_appear = 1;
        int current    = 1;

        for (int i = 1; i < input.length(); ++i) {
            if (input[i] == input[i - 1]) {
                current++;
            } else {
                max_appear = max(max_appear, current);
                current    = 1;
            }
        }
        max_appear = max(max_appear, current);
        cout << max_appear << "\n";
    }
}
