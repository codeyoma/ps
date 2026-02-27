// https://www.acmicpc.net/problem/32069
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

// multiset solution
ll  tele[300'001];
int bri[500'001];
int q, k;

void push(ll x) {
    if (k < x) {
        x = k;
    }

    if (x) {
        bri[x]++;
        q++;
    }
}

int main() {
    FAST_IO;

    ll  l;
    int n;
    cin >> l >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> tele[i];
    }

    for (int i = 0; i < n && k; ++i) {
        cout << "0\n";
        k--;
    }

    push(tele[0]);
    push(l - tele[n - 1]);

    for (int i = 0; i < n - 1; ++i) {
        ll dist = tele[i + 1] - tele[i];

        push(dist / 2);
        push((dist - 1) / 2);
    }

    int i = 1;
    while (k) {
        for (int t = q; k && t;) {
            cout << i << "\n";
            k--;
            t--;
        }
        q -= bri[i++];
    }

    return 0;
}

/* bfs solution
#include <queue>
#include <unordered_set>
int main() {
    FAST_IO;

    //   logic
    queue<pair<ll, ll>> q;
    unordered_set<ll>   check;

    ll l, n, k;
    cin >> l >> n >> k;

    for (ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        q.push({ temp, 0 });
    }

    while (k) {
        auto [pos, dist] = q.front();
        q.pop();

        if (check.find(pos) != check.end()) {
            continue;
        }
        cout << dist << "\n";
        check.insert(pos);
        k--;

        if (pos + 1 <= l) {
            q.push({ pos + 1, dist + 1 });
        }

        if (pos - 1 >= 0) {
            q.push({ pos - 1, dist + 1 });
        }
    }

    return 0;
}

*/