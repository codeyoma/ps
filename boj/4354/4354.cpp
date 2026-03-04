// https://www.acmicpc.net/problem/4354
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
    string s;

    while (true) {
        cin >> s;

        if (s == ".") {
            break;
        }

        int         j = 0;
        vector<int> t(s.size());

        for (int i = 1; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j]) {
                j = t[j - 1];
            }

            if (s[i] == s[j]) {
                t[i] = ++j;
            }
        }

        int pattern = s.size() - t.back();

        if (s.size() % pattern == 0) {
            cout << s.size() / pattern << "\n";
        } else {
            cout << "1\n";
        }
    }

    return 0;
}
