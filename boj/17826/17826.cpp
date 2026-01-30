// https://www.acmicpc.net/problem/17826
#include <functional>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    FAST_IO

    //   logic

    int         size = 50;
    int         my_score;
    vector<int> scores(50);

    for (int i = 0; i < size; ++i) {
        cin >> scores[i];
    }

    cin >> my_score;

    vector<int>::iterator pos = lower_bound(scores.begin(), scores.end(), my_score, greater<int>());

    vector<int>    upper     = { 5, 15, 30, 35, 45, 48, 50 };
    vector<string> gradeName = { "A+", "A0", "B+", "B0", "C+", "C0", "F" };

    int idx = upper_bound(upper.begin(), upper.end(), pos - scores.begin()) - upper.begin();
    cout << gradeName[idx];
}
