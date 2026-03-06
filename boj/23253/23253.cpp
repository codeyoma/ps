// https://www.acmicpc.net/problem/23253
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
    // 스택으로 시뮬레이션시 시간초과
    // 단조 감소로 체크
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int k, before = 0, current = 0;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            cin >> current;

            if (before == 0) {
                before = current;
                continue;
            }

            if (before < current) {
                cout << "No";
                return 0;
            }

            before = current;
        }
    }

    cout << "Yes";

    return 0;
}
