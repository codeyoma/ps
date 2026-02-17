// https://www.acmicpc.net/problem/24509
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
#include <unordered_set>
#include <vector>

struct Score {
    int i;
    int score;

    bool operator<(const Score& other) const {
        if (score == other.score) {
            return i < other.i;
        }
        return score > other.score;
    }
};

int main() {
    FAST_IO;

    //   logic
    vector<vector<Score>> s(4, vector<Score>());

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int idx, a, b, c, d;
        cin >> idx >> a >> b >> c >> d;

        s[0].push_back({ idx, a });
        s[1].push_back({ idx, b });
        s[2].push_back({ idx, c });
        s[3].push_back({ idx, d });
    }

    for (auto& v: s) {
        sort(v.begin(), v.end());
    }

    unordered_set<int> check;

    for (const auto& v: s) {
        for (const auto& e: v) {
            if (check.find(e.i) != check.end()) {
                continue;
            }
            cout << e.i << " ";
            check.insert(e.i);
            break;
        }
    }

    return 0;
}
