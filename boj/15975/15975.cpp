// https://www.acmicpc.net/problem/15975
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

#include <algorithm>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    ll n, answer = 0;
    cin >> n;

    vector<vector<ll>> dots(n + 1);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        dots[y].push_back(x);
    }

    for (auto& d: dots) {
        sort(d.begin(), d.end());
    }

    for (const auto& d: dots) {
        int size = d.size();

        if (size <= 1) {
            continue;
        }

        answer += d[1] - d[0];

        for (int i = 1; i < size - 1; ++i) {
            answer += min(d[i] - d[i - 1], d[i + 1] - d[i]);
        }

        answer += d[size - 1] - d[size - 2];
    }

    cout << answer;

    return 0;
}
