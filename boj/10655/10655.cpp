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

#include <cmath>

struct coor {
    int x;
    int y;
};

int main() {
    FAST_IO;

    //   logic
    int n, sum = 0, answer = _MAX;
    cin >> n;

    V<coor> check_point(n);
    V<int>  section_sum(n);
    V<int>  pass_sum(n);

    for (int i = 0; i < n; ++i) {
        cin >> check_point[i].x >> check_point[i].y;

        if (i) {
            section_sum[i] = abs(check_point[i].x - check_point[i - 1].x) + abs(check_point[i].y - check_point[i - 1].y);
            sum += section_sum[i];
        }

        if (i >= 2) {
            pass_sum[i] = abs(check_point[i].x - check_point[i - 2].x) + abs(check_point[i].y - check_point[i - 2].y);
        }
    }

    for (int pass = 1; pass < n - 1; ++pass) {
        answer = min(answer, sum - section_sum[pass] - section_sum[pass + 1] + pass_sum[pass + 1]);
    }

    cout << answer;

    END;
}
