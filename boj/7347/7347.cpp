// https://www.acmicpc.net/problem/7347
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int odd_count  = 0;
        int even_count = 0;

        for (int i = 0; i < n; ++i) {
            int mn;
            cin >> mn;

            if (mn & 1) {
                if (i & 1) {
                    odd_count++;
                } else {
                    even_count++;
                }
            }
        }

        LOG << odd_count << " " << even_count << endl;

        if (n & 1 || abs(odd_count - even_count) <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
