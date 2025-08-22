// https://www.acmicpc.net/problem/5218
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/5218/5218
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
        string x, y;
        cin >> x >> y;

        cout << "Distances:";
        for (int i = 0; i < x.length(); ++i) {
            if (x[i] <= y[i]) {
                cout << " " << y[i] - x[i];
            } else {
                cout << " " << (y[i] + 26) - x[i];
            }
        }
        cout << "\n";
    }
}
