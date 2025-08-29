// https://www.acmicpc.net/problem/2562
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2562/2562
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

    int cur_max       = MIN;
    int cur_max_index = 0;

    for (int i = 1; i <= 9; ++i) {
        int temp;
        cin >> temp;

        if (temp > cur_max) {
            cur_max       = temp;
            cur_max_index = i;
        }
    }
    cout << cur_max << "\n";
    cout << cur_max_index;
}
