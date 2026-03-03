// https://www.acmicpc.net/problem/9506
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

#include <numeric>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int n;

    while (true) {
        cin >> n;

        if (n == -1) {
            break;
        }

        vector<int> s;

        for (int i = 1; i < n; ++i) {
            if (n % i == 0) {
                s.push_back(i);
            }
        }

        if (n == accumulate(s.begin(), s.end(), 0)) {
            cout << n << " = ";
            for (int i = 0; i < s.size(); ++i) {
                cout << s[i];
                if (i != s.size() - 1) {
                    cout << " + ";
                }
            }
            cout << "\n";
        } else {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0;
}
