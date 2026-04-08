// https://www.acmicpc.net/problem/32371
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

    vector<string> key(4);
    string         t;

    for (int i = 0; i < 4; ++i) {
        cin >> key[i];
    }

    cin >> t;

    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 7; ++j) {
            bool found = true;
            for (int k = 0; k < 3 && found; ++k) {
                for (int l = 0; l < 3 && found; ++l) {
                    if (t.find(key[i + k][j + l]) == string::npos) {
                        found = false;
                    }
                }
            }
            if (found) {
                cout << key[i + 1][j + 1];
            }
        }
    }

    return 0;
}
