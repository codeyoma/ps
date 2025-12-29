// https://www.acmicpc.net/problem/2851
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>

int main() {
    fast_io();

    //   logic

    int answer = 0;
    int p_sum  = 0;

    for (int i = 0; i < 10; ++i) {
        int temp;
        cin >> temp;

        p_sum += temp;

        if (abs(100 - p_sum) <= abs(100 - answer)) {
            answer = p_sum;
        }
    }
    cout << answer;
}
