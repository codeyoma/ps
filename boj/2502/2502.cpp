// https://www.acmicpc.net/problem/2502
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

int main() {
    FAST_IO;

    //   logic
    int d, k;
    cin >> d >> k;

    // 첫날, 둘째날 각기 사용한 양의 DP가, 결국 1차원 피보나치랑 같음
    V<int> dp(d + 1);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= d; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 1;; ++i) {
        if ((k - (dp[d - 2] * i)) % dp[d - 1] == 0) {
            cout << i << "\n";
            cout << (k - (dp[d - 2] * i)) / dp[d - 1];
            break;
        }
    }

    END;
}
