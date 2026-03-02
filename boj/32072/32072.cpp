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

    // 1. 한 번의 뽑아내기는 경로 위에서 아래 값을 위로 한칸 복사, 루트 값은 리프에 가서 삭제
    // 2. 따라서 루트가 어느 자식 c를 선택하면, 그 자식 부분트리 내부는 “그 부분트리만 따로 뽑아, 뽑아내기 1회를 한 것과 같은 상태”
    // 3. 루트에서 보는 다음 값은 항상 “직속 자식들 중 최소”이므로, 루트 수열은 자식 수열들을 “루트 최소 병합”한 것과 동일
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
