// https://www.acmicpc.net/problem/28237
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

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

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

using namespace std;
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <cmath>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    int n, n1, n2;
    cin >> n;
    n1 = n + 1;
    n2 = n + 2;

    vector<int> fn;
    vector<int> fn2;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            fn.push_back(i);
        }
    }

    for (int i = 1; i <= n2; ++i) {
        if (n2 % i == 0) {
            fn2.push_back(i);
        }
    }

    for (const auto& a: fn) {
        for (const auto& b: fn2) {
            int c = n / a, d = n2 / b;

            if (b * c + a * -d == n1) {
                cout << a << " " << b << " " << c << " " << -d;
                return 0;
            } else if (-b * c + a * d == n1) {
                cout << a << " " << -b << " " << c << " " << d;
                return 0;
            }
        }
    }

    cout << "-1";

    return 0;
}
