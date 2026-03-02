// https://www.acmicpc.net/problem/1764
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
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int n, m;
    cin >> n >> m;
    vector<string> d(n);
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;

        auto it = lower_bound(d.begin(), d.end(), t);

        if (it != d.end() && *it == t) {
            answer.push_back(t);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";

    for (const auto& e: answer) {
        cout << e << "\n";
    }

    return 0;
}

/*
#include <algorithm>
#include <unordered_set>
#include <vector>
void set_solution()
{
    unordered_set<string> s;
    vector<string> answer;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    for (int i = 0; i < m; ++i) {
        string temp;
        cin >> temp;
        if (s.count(temp))
            answer.push_back(temp);
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (const auto& i : answer) {
        cout << i << "\n";
    }
}
*/