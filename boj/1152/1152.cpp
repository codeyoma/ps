// https://www.acmicpc.net/problem/1152
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1152/1152
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
    getline(cin, input);

    int bais = 0;
    int sum  = 0;

    LOG << input << "\n";

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] != ' ') {
            bais = 1;
        } else {
            sum += bais;
            bais = 0;
        }

        if (i == input.length() - 1) {
            sum += bais;
        }
    }
    cout << sum;
}
