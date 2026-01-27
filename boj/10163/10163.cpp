// https://www.acmicpc.net/problem/10163
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

int main() {
    FAST_IO

    //   logic

    vector<vector<int>> t(1001, vector<int>(1001, -1));

    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        int sum = 0;
        for (int j = y; j < y + h; ++j) {
            for (int k = x; k < x + w; ++k) {
                if (t[j][k] != -1) {
                    p[t[j][k]] -= 1;
                }
                sum += 1;
                t[j][k] = i;
            }
        }
        p[i] = sum;
    }

    for (const auto& a: p) {
        cout << a << "\n";
    }
}
