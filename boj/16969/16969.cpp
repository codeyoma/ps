// https://www.acmicpc.net/problem/16969
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

#include <string>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    ll m      = 1'000'000'009;
    ll answer = 1;
    ll bias   = 0;

    string n;
    cin >> n;

    for (int i = 0; i < n.length(); ++i) {
        if (i > 0 && n[i] == n[i - 1]) {
            bias = 1;
        } else {
            bias = 0;
        }

        if (n[i] == 'd') {
            answer = (answer * (10 - bias)) % m;
        } else {
            answer = (answer * (26 - bias)) % m;
        }
    }
    cout << answer;

    return 0;
}
