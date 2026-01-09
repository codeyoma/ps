// https://www.acmicpc.net/problem/33736
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
#include <vector>

int main() {
    fast_io();

    //   logic

    int n;
    cin >> n;
    vector<int> o(n);
    vector<int> v(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> o[i];
        v[o[i]]++;
    }

    int cost = 0;
    for (int i = 0; i <= n; ++i) {
        cout << max(cost, v[i]) << "\n";

        if (v[i] == 0) {
            cost++;
        }
    }
}
