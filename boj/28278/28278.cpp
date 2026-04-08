// https://www.acmicpc.net/problem/28278
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

// typedef long long ll;
using ll  = long long;
using ull = unsigned long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <vector>

int main() {
    FAST_IO;

    //   logic

    vector<int> s;
    int         n;
    cin >> n;

    while (n--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int t;
            cin >> t;

            s.push_back(t);
        } else if (cmd == 2) {
            if (s.size()) {
                cout << s.back() << "\n";
                s.pop_back();
            } else {
                cout << "-1\n";
            }
        } else if (cmd == 3) {
            cout << s.size() << "\n";
        } else if (cmd == 4) {
            if (s.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (s.size()) {
                cout << s.back() << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    END;
}
