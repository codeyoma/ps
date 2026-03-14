// https://www.acmicpc.net/problem/31866
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

#include <vector>

int main() {
    FAST_IO;

    //   logic

    vector<int> table = {
        0b011110,
        0b000000,
        0b010111,
        0b000000,
        0b000000,
        0b110110,
    };

    int a, b;
    cin >> a >> b;

    bool a_win_state = table[a] & (32 >> b);
    bool b_win_state = table[b] & (32 >> a);

    if (a_win_state == b_win_state) {
        cout << "=";
    } else if (a_win_state) {
        cout << ">";
    } else {
        cout << "<";
    }

    return 0;
}
