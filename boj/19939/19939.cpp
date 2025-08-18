// https://www.acmicpc.net/problem/19939
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

int main() {
    //   logic
    int n, k;
    cin >> n >> k;

    n -= (k + 1) * k / 2;
    n %= k;

    if (n > 0) {
        cout << k;
        return 0;
    } else if (n == 0) {
        cout << k - 1;
        return 0;
    }
    cout << -1;
}
