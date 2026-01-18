// https://www.acmicpc.net/problem/2480
#include <algorithm>
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

#include <iostream>
#include <vector>

typedef struct Dice {
    int index;
    int value;
} Dice;

int main() {
    FAST_IO

    //   logic

    vector<int>  o(6 + 1);
    vector<Dice> d;

    for (int i = 0; i < 3; ++i) {
        int temp;
        cin >> temp;
        o[temp]++;
    }

    for (int i = 1; i <= 6; ++i) {
        if (o[i]) {
            d.push_back({ i, o[i] });
        }
    }

    sort(d.begin(), d.end(), [](const Dice& a, const Dice& b) {
        if (a.value == b.value) {
            return a.index > b.index;
        }
        return a.value > b.value;
    });

    switch (d[0].value) {
        case 1:
            cout << 100 * d[0].index;
            break;
        case 2:
            cout << 1000 + 100 * d[0].index;
            break;
        case 3:
            cout << 10000 + 1000 * d[0].index;
            break;
    }
}
