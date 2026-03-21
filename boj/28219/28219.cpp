// https://www.acmicpc.net/problem/28219
#include <numeric>
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
#include <stack>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    enum state {
        YET,
        WIP,
        DONE
    };

    int n, k;

    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<int>         depth(n + 1, 0);
    vector<state>       visit(n + 1, state::YET);
    stack<int>          dfs;
    int                 count = 0;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs.push(1);

    while (!dfs.empty()) {
        int x = dfs.top();

        if (visit[x] == state::DONE) {
            dfs.pop();
            continue;
        }

        if (visit[x] == state::YET) {
            for (const auto& child: adj[x]) {
                if (visit[child] == state::YET) {
                    dfs.push(child);
                }
            }
            visit[x] = state::WIP;
            continue;
        }

        int first_dist  = 0;
        int second_dist = 0;

        for (const auto& child: adj[x]) {
            if (visit[child] != DONE) {
                continue;
            }

            int cand = depth[child];
            // int cand = depth[child] + 1;

            if (cand > first_dist) {
                swap(cand, first_dist);
            }

            second_dist = max(second_dist, cand);
        }

        if (first_dist + second_dist >= k) {
            count++;
            depth[x] = 0;
            // depth[x] = -1;
        } else {
            depth[x] = first_dist + 1;
            // depth[x] = first_dist;
        }

        visit[x] = state::DONE;
        dfs.pop();
    }

    cout << count;

    return 0;
}
