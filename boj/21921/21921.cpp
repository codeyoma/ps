// https://www.acmicpc.net/problem/21921
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

int main() {
    FAST_IO;

    //   logic
    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int answer     = 0;
    int answer_cnt = 0;
    int sum        = 0;

    for (int i = 0; i < x; ++i) {
        sum += v[i];
    }

    if (sum > answer) {
        answer     = sum;
        answer_cnt = 1;
    }

    for (int i = x; i < n; ++i) {
        sum -= v[i - x];
        sum += v[i];

        if (sum > answer) {
            answer     = sum;
            answer_cnt = 1;
        } else if (sum == answer) {
            answer_cnt++;
        }
    }

    if (answer == 0) {
        cout << "SAD";
    } else {
        cout << answer << "\n"
             << answer_cnt;
    }

    return 0;
}
