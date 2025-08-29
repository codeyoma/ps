// https://www.acmicpc.net/problem/10870
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10870/10870
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

int fibo(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int dp(int n) {
    if (n <= 1) {
        return n;
    }

    int before = 1;
    int after  = 1;

    for (int i = 3; i <= n; ++i) {
        int temp = before;
        before   = after;
        after    = temp + before;
    }

    return after;
}

int main() {
    int n;
    cin >> n;

    // dp
    cout << dp(n);

    // recursive
    // cout << fibo(n);
}