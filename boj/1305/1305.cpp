// https://www.acmicpc.net/problem/1305
#include <algorithm>
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

int failure_fn(string& pattern) {
    vector<int> table(pattern.size());
    int         j = 0;

    for (int i = 1; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table.back();
}

int main() {
    FAST_IO;

    //   logic
    int    l;
    string s;
    cin >> l >> s;

    cout << l - failure_fn(s);

    return 0;
}
