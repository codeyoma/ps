// https://www.acmicpc.net/problem/1356
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

#include <string>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    string s;
    cin >> s;

    bool check = false;

    for (size_t i = 1; i < s.length(); ++i) {
        string a = s.substr(0, i);
        string b = s.substr(i);

        int a_sum = 1;
        int b_sum = 1;

        for (size_t j = 0; j < a.length(); ++j) {
            a_sum *= a[j] - '0';
        }

        for (size_t k = 0; k < b.length(); ++k) {
            b_sum *= b[k] - '0';
        }

        if (a_sum == b_sum) {
            check = true;
        }
    }

    if (check) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
