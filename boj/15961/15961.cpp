// https://www.acmicpc.net/problem/15961
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    fast_io();

    //   logic

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int answer = _MIN;

    unordered_map<int, int> w;

    for (int i = 0; i < k; ++i) {
        w[v[i]]++;
    }

    for (int i = 1; i < n; ++i) {
    }
}
