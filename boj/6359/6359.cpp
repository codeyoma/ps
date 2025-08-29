// https://www.acmicpc.net/problem/6359
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/6359/6359
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

    //   logic
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // false = locked
        // true = opened
        vector<bool> v(n + 1);

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                v[j] = !v[j];
            }
        }

        cout << count_if(v.begin(), v.end(), [](const bool& room) {
            return room;
        }) << "\n";
    }
}
