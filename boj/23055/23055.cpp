// https://www.acmicpc.net/problem/23055
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/23055/23055
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>

int main() {
    fast_io();

    //   logic
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || i == n || j == 1 || j == n || i == j || n - i == j - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
