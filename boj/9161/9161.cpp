// https://www.acmicpc.net/problem/9161
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

int main() {
    FAST_IO;

    //   logic

    for(int i = 100; i <=999; ++i){
        for(int j = 100; j <= 999; ++j){
            if (i % 111 == 0 && i == j){
                continue;
            }

            if (i % 10 != j / 100){
                continue;
            }

            int a = i / 10;
            int b = j % 100;

            if (i * b == a * j){
                cout << i << " / " << j << " = " << a << " / " << b << "\n";
            }

        }
    }

    return 0;
}
