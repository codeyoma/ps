// https://www.acmicpc.net/problem/1701
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

#include <string>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int    answer = 0;
    string s;
    cin >> s;

    for (int start = 0; start < s.size(); ++start) {
        int m = s.size() - start;

        vector<int> t(m);
        int         j = 0;

        for (int i = 1; i < m; ++i) {
            while (j > 0 && s[start + i] != s[start + j]) {
                j = t[j - 1];
            }

            if (s[start + i] == s[start + j]) {
                t[i] = ++j;

                answer = max(answer, t[i]);
            }
        }
    }

    cout << answer;

    return 0;
}
