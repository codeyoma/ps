// https://www.acmicpc.net/problem/15272
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
#include <string>

int main() {
    FAST_IO

    //   logic

    string s;
    cin >> s;

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == 's' && s[i + 1] == 's') {
            cout << "hiss";
            return 0;
        }
    }
    cout << "no hiss";
}
