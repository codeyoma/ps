// https://www.acmicpc.net/problem/28214
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/28214/28214
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

#include <iostream>

int main() {
    fast_io();

    //   logic
    int n, k, p, not_sell = 0;
    cin >> n >> k >> p;

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < k; ++j) {
            int temp;
            cin >> temp;

            if (!temp) {
                count++;
            }
        }
        if (count >= p) {
            not_sell++;
        }
    }
    cout << n - not_sell;
}
