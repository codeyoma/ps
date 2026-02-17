// https://www.acmicpc.net/problem/4344
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

#include <iomanip>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int c;
    cin >> c;

    while (c--) {
        double n, sum = 0;

        cin >> n;
        vector<double> s(n);

        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            sum += s[i];
        }

        int    cnt = 0;
        double avg = (double)sum / (double)n;

        for (const auto& e: s) {
            if (avg < e) {
                cnt++;
            }
        }

        cout << fixed << setprecision(3) << (double)cnt / n * 100 << "%\n";
    }

    return 0;
}
