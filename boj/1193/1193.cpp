// https://www.acmicpc.net/problem/1193
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>

int main() {
    FAST_IO

    //   logic
    int x;
    cin >> x;

    int n = 1;

    while ((n * (n + 1) / 2) < x) {
        n++;
    }

    int prev = (n * (n - 1)) / 2;
    int pos  = x - prev;

    if (n % 2) {
        cout << n - pos + 1 << "/" << pos;
    } else {
        cout << pos << "/" << n - pos + 1;
    }
}
