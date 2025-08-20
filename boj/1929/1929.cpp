// https://www.acmicpc.net/problem/1929
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

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    //   logic
    int m, n;
    cin >> m >> n;

    vector<bool> t(n + 1, true);
    t[1] = false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (t[i] == false) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            t[j] = false;
        }
    }

    for (int i = m; i <= n; ++i) {
        if (t[i]) {
            cout << i << "\n";
            LOG << i << "\n";
        }
    }
}
