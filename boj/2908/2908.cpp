// https://www.acmicpc.net/problem/2908
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2908/2908
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

int reverse_number(int n) {
    int rev = 0;

    while (n > 0) {
        rev = (rev * 10) + n % 10;
        n /= 10;
    }

    return rev;
}

int main() {
    fast_io();

    //   logic

    int a, b;

    cin >> a >> b;

    a = reverse_number(a);
    b = reverse_number(b);

    if (a > b) {
        cout << a;
    } else {
        cout << b;
    }
}
