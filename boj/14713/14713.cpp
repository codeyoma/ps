// https://www.acmicpc.net/problem/14713
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
#include <queue>
#include <sstream>

int main() {
    FAST_IO

    //   logic
    int n;
    cin >> n;
    cin.ignore();

    queue<string> b[100];
    queue<string> main;

    for (int i = 0; i < n; ++i) {
        string s, word;
        getline(cin, s);

        istringstream iss(s);

        while (iss >> word) {
            b[i].push(word);
        }
    }

    {
        string s, word;
        getline(cin, s);

        istringstream iss(s);

        while (iss >> word) {
            main.push(word);
        }
    }

    // ----

    while (!main.empty()) {
        bool find = false;

        for (int i = 0; i < n; ++i) {
            if (!b[i].empty() && main.front() == b[i].front()) {
                b[i].pop();
                main.pop();
                find = true;
                break;
            }
        }

        if (!find) {
            cout << "Impossible";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!b[i].empty()) {
            cout << "Impossible";
            return 0;
        }
    }
    cout << "Possible";
}
