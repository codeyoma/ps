// https://www.acmicpc.net/problem/13325
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
    int n, size, p_size;
    int answer = 0;
    cin >> n;
    size   = (1 << (n + 1)) - 1;
    p_size = (1 << (n)) - 1;

    vector<int> t(size + 1, 0);
    vector<int> dp(size + 1, 0);

    for (int i = 2; i <= size; ++i) {
        cin >> t[i];
    }

    for (int i = p_size; i >= 1; --i) {
        int l = i * 2;
        int r = i * 2 + 1;

        dp[i] = max(t[l] + dp[l], t[r] + dp[r]);

        answer += dp[i] - dp[l] + dp[i] - dp[r];
    }

    cout << answer;

    return 0;
}
