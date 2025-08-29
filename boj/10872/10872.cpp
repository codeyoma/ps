// https://www.acmicpc.net/problem/10872
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10872/10872
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

int fac(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fac(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << fac(n);
}