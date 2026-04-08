// https://www.acmicpc.net/problem/28220
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

#define END   \
    return 0;

// typedef long long ll;
using ll  = long long;
using ull = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <algorithm>
#include <cstdlib>
#include <vector>

int main() {
    FAST_IO;

    //   logic

    int n;
    ull L, R;
    cin >> n >> L >> R;

    vector<ull> a(n + 1);

    // S = A1 + ... + An -> 초기 배열 값
    // T = B1 + ... + Bn -> 최적 상태 배열
    // i번째 울타리 지나는 비용 |Si - Ti|
    // 전체 비용 |S1 - T1| + ... + |S_n-1 - T_n-1| = |S - T|
    // - 마지막 누적 항은 서로 같기에 0 (최대 블록수는 같으니)

    // Ci = Bi - L
    // 미리 최소 L만큼 깔아두기
    // sig B1 to Bi = i*L + sig C1 to Ci
    // prefix[i] = (A1 - L) + ... + (Ai - L)

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    const int E = static_cast<int>(R - L);

    vector<ull> prefix(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + (a[i] - L);
    }

    const ull C = prefix[n];

    if (C < 0 || C > 1LL * n * E) {
        cout << -1 << '\n';
        return 0;
    }

    const int totalExtra = static_cast<int>(C);

    vector<vector<ull>> cur(n + 1, vector<ull>(totalExtra + 1, __MAX));

    cur[0][0] = 0;

    for (int v = 0; v <= E; ++v) {
        for (int i = 1; i <= n; ++i) {
            const int limit = min(totalExtra, i * v);

            for (int sum = v; sum <= limit; ++sum) {
                if (cur[i - 1][sum - v] == __MAX) {
                    continue;
                }

                const ull moveCost = llabs(prefix[i] - sum);

                cur[i][sum] = min(cur[i][sum],
                                  cur[i - 1][sum - v] + moveCost);
            }
        }
    }

    cout << cur[n][totalExtra] << '\n';

    END;
}
