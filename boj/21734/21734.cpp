// https://www.acmicpc.net/problem/21734
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/21734/21734
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
    for (const auto& c: input) {
        int limit = 0;
        int cycle = c;
        while (cycle > 0) {
            LOG << cycle << " ";
            limit += cycle % 10;
            cycle /= 10;
        }
        LOG << "\n";
        LOG << limit << "\n";
        for (int i = 0; i < limit; ++i) {
            cout << c;
        }
        cout << "\n";
    }
}
