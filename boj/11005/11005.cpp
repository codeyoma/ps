// https://www.acmicpc.net/problem/11005
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

#include <algorithm>
#include <string>

string base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void format(int n, const int& b) {
    string s;

    while (n > 0) {
        s.push_back(base[n % b]);
        n = n / b;
    }

    reverse(s.begin(), s.end());

    cout << s;
}

void format_(int n, const int& b) {
    if (n < b) {
        cout << base[n];
        return;
    }

    format_(n / b, b);

    cout << base[n % b];
}

int main() {
    FAST_IO;

    //   logic
    int n, b;
    cin >> n >> b;

    format(n, b);

    return 0;
}
