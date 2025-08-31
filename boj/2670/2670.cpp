// https://www.acmicpc.net/problem/2670
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2670/2670
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

#include <iomanip>
#include <iostream>

int main() {
    fast_io();

    //   logic

    int n;
    cin >> n;

    double answer  = MIN;
    double cur_max = MIN;

    while (n--) {
        double temp;
        cin >> temp;

        cur_max = max(cur_max * temp, temp);
        answer  = max(answer, cur_max);
    }

    cout << fixed << setprecision(3) << answer << endl;
}
