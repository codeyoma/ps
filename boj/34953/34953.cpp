// https://www.acmicpc.net/problem/34953
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

#define END   \
    return 0;

#include <vector>

template<typename T>
using VV = vector<vector<T>>;

template<typename T>
using V = vector<T>;

// typedef long long ll;
using LL  = long long;
using ULL = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr LL  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr LL  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <string>

int main() {
    FAST_IO;

    //   logic
    string base = "SSHS";
    string vias = "SHS";
    int    n;
    cin >> n;

    for (int i = 0; i < n && i < 4; ++i) {
        cout << base[i];
    }

    int remain = n - 4;

    for (int i = 0; i < remain / 3; ++i) {
        cout << vias;
    }

    for (int i = 0; i < remain % 3; ++i) {
        cout << vias[i];
    }

    END;
}
