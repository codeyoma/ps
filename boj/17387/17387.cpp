// https://www.acmicpc.net/problem/17387
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

struct P {
    ll x;
    ll y;
};

int ccw(const P& A, const P& B, const P& C) {
    // ll t1 = A.x * B.y + B.x * C.y + C.x * A.y;
    // ll t2 = A.y * B.x + B.y * C.x + C.y * A.x;
    ll t1 = (B.x - A.x) * (C.y - A.y);
    ll t2 = (C.x - A.x) * (B.y - A.y);

    if (t1 - t2 > 0) { // 반시계
        return 1;
    } else if (t1 - t2 == 0) { // 일직선
        return 0;
    } else { // 시계
        return -1;
    }
}

bool onSegment(const P& a, const P& b, const P& p) {
    if (ccw(a, b, p) != 0) {
        return false;
    }
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segIntersect(const P& a, const P& b, const P& c, const P& d) {
    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    if (ab_c * ab_d < 0 && cd_a * cd_b < 0) {
        return true;
    }

    if (ab_c == 0 && onSegment(a, b, c)) {
        return true;
    }
    if (ab_d == 0 && onSegment(a, b, d)) {
        return true;
    }
    if (cd_a == 0 && onSegment(c, d, a)) {
        return true;
    }
    if (cd_b == 0 && onSegment(c, d, b)) {
        return true;
    }

    return false;
}
int main() {
    FAST_IO;

    //   logic
    P a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    cout << segIntersect(a, b, c, d);

    return 0;
}
