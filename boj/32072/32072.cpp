// https://www.acmicpc.net/problem/32072
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

#include <queue>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int n;
    cin >> n;

    vector<vector<int>> child(n + 1);
    vector<int>         weight(n + 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;

        child[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }

    pq.push({ weight[1], 1 });

    // 최소값으로 찾아가니, pq로 탐색 및 추가
    while (!pq.empty()) {
        auto [w, idx] = pq.top();
        pq.pop();

        cout << w << "\n";

        for (const auto& c: child[idx]) {
            pq.push({ weight[c], c });
        }
    }

    return 0;
}
