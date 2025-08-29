// https://www.acmicpc.net/problem/2506
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2506/2506
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
    int n, sum = 0, bias = 0;
    cin >> n;

    while (n--) {
        int temp;
        cin >> temp;

        if (temp) {
            bias++;
        } else {
            bias = 0;
        }

        sum += bias;
    }
    cout << sum;
}
