// https://www.acmicpc.net/problem/11758
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

typedef struct {
    int x;
    int y;
} coor;

int ccw(coor& a, coor& b, coor& c) {
    int r = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);

    if (r == 0) {
        return 0;
    } else if (r > 0) {
        return 1;
    }
    return -1;
}

int main() {
    FAST_IO;

    //   logic

    vector<coor> c(3);

    for (int i = 0; i < 3; ++i) {
        cin >> c[i].x >> c[i].y;
    }
    cout << ccw(c[0], c[1], c[2]);

    END;
}
