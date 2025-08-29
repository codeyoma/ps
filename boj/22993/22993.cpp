// https://www.acmicpc.net/problem/22993
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/22993/22993
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

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    fast_io();

    int n;
    cin >> n;

    long long my_dmg;
    cin >> my_dmg;

    vector<long long> user(n - 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        cin >> user[i];
    }

    sort(user.begin(), user.end());

    for (const auto& u: user) {
        LOG << u << endl;
        if (u >= my_dmg) {
            cout << "No";
            return 0;
        }
        my_dmg += u;
    }

    cout << "Yes";
}