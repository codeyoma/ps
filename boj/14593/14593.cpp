// https://www.acmicpc.net/problem/14593
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

#include <algorithm>
#include <iostream>
#include <vector>

struct user {
    int index;
    int s;
    int c;
    int l;
};

int main() {
    FAST_IO

    //   logic
    int n;
    cin >> n;
    vector<user> v;

    for (int i = 1; i <= n; ++i) {
        int s, c, l;
        cin >> s >> c >> l;

        v.push_back({ i, s, c, l });
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.s != b.s) {
            return a.s > b.s;
        }

        if (a.c != b.c) {
            return a.c < b.c;
        }

        return a.l < b.l;
    });

    cout << v.front().index;
}
