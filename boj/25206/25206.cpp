// https://www.acmicpc.net/problem/25206
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

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    FAST_IO

    //   logic

    unordered_map<string, float> list = {
        { "A+", 4.5 },
        { "A0", 4.0 },
        { "B+", 3.5 },
        { "B0", 3.0 },
        { "C+", 2.5 },
        { "C0", 2.0 },
        { "D+", 1.5 },
        { "D0", 1.0 },
        {  "F", 0.0 },
    };

    float gpa    = 0.0;
    float credit = 0;

    for (int i = 0; i < 20; ++i) {
        string l, score;
        float  c;

        cin >> l >> c >> score;

        if (score == "P") {
            continue;
        } else {
            credit += c;
            gpa += list[score] * c;
        }
    }

    cout << fixed << setprecision(6) << gpa / credit;
}
