// https://www.acmicpc.net/problem/13220
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

vector<int> failure_fn(const vector<int>& pattern) {
    vector<int> t(pattern.size());
    int         j = 0;

    for (int i = 1; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = t[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            t[i] = ++j;
        }
    }

    return t;
}

bool kmp(const vector<int>& s, const vector<int>& p) {
    vector<int> t = failure_fn(p);
    int         j = 0;

    for (int i = 0; i < s.size(); ++i) {
        while (j > 0 && s[i] != p[j]) {
            j = t[j - 1];
        }

        if (s[i] == p[j]) {
            if (j == p.size() - 1) {
                return true;
            }
            j++;
        }
    }

    return false;
}

int main() {
    FAST_IO;

    //   logic

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> t = a;

    a.insert(a.end(), t.begin(), t.end());

    if (kmp(a, b)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
