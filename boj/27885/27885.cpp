// https://www.acmicpc.net/problem/27885
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

#include <vector>

template<typename T>
using VV = vector<vector<T>>;

template<typename T>
using V = vector<T>;

// typedef long long ll;
using LL  = long long;
using ULL = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr LL  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr LL  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <unordered_set>

int time_to_int(const string& t) {
    int r = 0;

    r += stoi(t.substr(0, 2)) * 3600;
    r += stoi(t.substr(3, 2)) * 60;
    r += stoi(t.substr(6, 2));

    return r;
}

int main() {
    FAST_IO;

    //   logic
    int c, h, z;
    cin >> c >> h;
    z = c + h;

    unordered_set<int> close_time;

    while (z--) {
        string t;
        cin >> t;

        int int_t = time_to_int(t);

        for (int i = 0; i < 40; ++i) {
            close_time.insert((int_t + i));
        }
    }

    cout << 3600 * 24 - close_time.size();

    END;
}
