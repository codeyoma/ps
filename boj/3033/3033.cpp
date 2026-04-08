// https://www.acmicpc.net/problem/3033
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

// typedef long long ll;
using ll  = long long;
using ull = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    ll     mod1 = 1'000'000'009;
    ll     mod2 = _MAX;
    ll     base = 29;
    int    L;
    string s;

    cin >> L >> s;

    vector<ll> t1(L + 1, 1);
    vector<ll> t2(L + 1, 1);

    for (int i = 1; i <= L; ++i) {
        t1[i] = (t1[i - 1] * base) % mod1;
        t2[i] = (t2[i - 1] * base) % mod2;
    }

    auto is_twice = [&](const int& m) {
        if (m == 0) {
            return true;
        }

        ll hash1  = 0;
        ll hash2  = 0;
        ll power1 = t1[m - 1];
        ll power2 = t2[m - 1];

        for (int i = 0; i < m; ++i) {
            hash1 = (hash1 * base + (s[i] - 'a' + 1)) % mod1;
            hash2 = (hash2 * base + (s[i] - 'a' + 1)) % mod2;
        }

        unordered_set<ull> check;
        check.reserve((L - m + 1));
        check.max_load_factor(0.7f);
        check.insert(hash1 << 32 | hash2);

        for (int i = 0; i < L - m; ++i) {
            hash1 = (hash1 - ((s[i] - 'a' + 1) * power1) % mod1 + mod1) % mod1;
            hash1 = (hash1 * base + ((s[i + m] - 'a' + 1))) % mod1;
            hash2 = (hash2 - ((s[i] - 'a' + 1) * power2) % mod2 + mod2) % mod2;
            hash2 = (hash2 * base + ((s[i + m] - 'a' + 1))) % mod2;

            if (!check.insert(hash1 << 32 | hash2).second) {
                return true;
            }
        }

        return false;
    };

    int l      = 0;
    int r      = L;
    int answer = 0;

    while (l <= r) {
        int m = l + ((r - l) / 2);

        if (is_twice(m)) {
            answer = m;
            l      = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << answer;

    return 0;
}

