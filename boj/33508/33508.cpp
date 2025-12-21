// https://www.acmicpc.net/problem/33508
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

constexpr int MAX_  = 1'234'567'891;
constexpr int MIN_  = -MAX_;
constexpr ll  MAX__ = 1'111'111'111'111'111'111LL;
constexpr ll  MIN__ = -MAX__;

//--------------------------------------------------------------------------------------------------

#include <iostream>

int main() {
    fast_io();

    //   logic
}
