// https://www.acmicpc.net/problem/17269
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

    vector<int> line = {
        3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1
    };

    int n, m;
    cin >> n >> m;

    vector<int> d;

    string s1, s2, s;
    cin >> s1 >> s2;

    int i = 0;
    for (; i < s1.length() && i < s2.length(); ++i) {
        s.push_back(s1[i]);
        s.push_back(s2[i]);
    }

    if (i < s1.length()) {
        s.insert(i * 2, s1, i);
    }
    if (i < s2.length()) {
        s.insert(i * 2, s2, i);
    }

    for (const auto c: s) {
        d.push_back(line[c - 'A']);
    }

    while (d.size() > 2) {
        vector<int> next_d(d.size() - 1);

        for (int i = 0; i < d.size() - 1; ++i) {
            next_d[i] = (d[i] + d[i + 1]) % 10;
        }

        d = next_d;
    }

    cout << d[0] * 10 + d[1] << "%";
    return 0;
}
