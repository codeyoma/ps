// https://www.acmicpc.net/problem/15702
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
    int n, m;
    cin >> n >> m;

    vector<int> score(n);

    int ans_score  = -1;
    int ans_number = 100'001;

    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    for (int i = 0; i < m; ++i) {
        int sum = 0;
        int number;

        cin >> number;

        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == 'O') {
                sum += score[j];
            }
        }

        if (ans_score < sum || (ans_score == sum && number < ans_number)) {
            ans_number = number;
            ans_score  = sum;
        }
    }

    cout << ans_number << " " << ans_score;

    return 0;
}
