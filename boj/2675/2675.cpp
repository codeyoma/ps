// https://www.acmicpc.net/problem/2675
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2675/2675
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
    int n;
    cin >> n;
    while (n--) {
        int    r;
        string s;
        cin >> r >> s;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < r; ++j) {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}
