// https://www.acmicpc.net/problem/2303
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

#include <iostream>
#include <vector>
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

#define END   \
    return 0;

template<typename T>
using VV = vector<vector<T>>;

template<typename T>
using V = vector<T>;

// typedef long long ll;
using LL  = long long;
using ULL = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr LL  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr LL  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

int dfs(const V<int>& cards, V<bool>& visit, int depth, int value, int index) {
    if (depth == 3) {
        return value % 10;
    }

    int m = 0;

    for (int i = index; i < 5; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            m        = max(m, dfs(cards, visit, depth + 1, value + cards[i], i + 1));
            visit[i] = false;
        }
    }

    return m;
}

int main() {
    FAST_IO;

    //   logic
    int n, answer = 0, answer_index = 1;
    cin >> n;
    VV<int> game(n, V<int>(5));
    V<bool> visit(5);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> game[i][j];
        }
        int temp = dfs(game[i], visit, 0, 0, 0);

        if (answer <= temp) {
            answer       = temp;
            answer_index = i;
        }

        fill(visit.begin(), visit.end(), false);
    }

    cout << answer_index + 1;

    END;
}
