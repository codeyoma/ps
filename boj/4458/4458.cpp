// https://www.acmicpc.net/problem/4458
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/4458/4458
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
    int    n;
    string cycle;
    getline(cin, cycle);

    n = stoi(cycle);
    for (int i = 0; i < n; ++i) {
        string input;
        getline(cin, input);

        if ('a' <= input.front() && input.front() <= 'z') {
            input[0] -= 'a' - 'A';
        }
        cout << input << "\n";
    }
}
