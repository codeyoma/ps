// https://www.acmicpc.net/problem/7568
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

struct info {
    int weight;
    int height;
};

int main() {
    FAST_IO;

    //   logic
    int n;
    cin >> n;

    V<info> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].weight >> v[i].height;
    }

    for (int cur = 0; cur < n; ++cur) {
        int rank = 1;

        for (int o = 0; o < n; ++o) {
            if (cur == o) {
                continue;
            }
            if (v[o].height > v[cur].height && v[o].weight > v[cur].weight) {
                rank++;
            }
        }
        cout << rank << " ";
    }

    END;
}
