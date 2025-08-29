// https://www.acmicpc.net/problem/2577
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2577/2577
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
#include <vector>

int main() {
    fast_io();

    //   logic

    int a, b, c;
    cin >> a >> b >> c;

    int result = a * b * c;

    vector<int> v(10);

    while (result > 0) {
        v[result % 10]++;
        result /= 10;
    }

    for (const auto& i: v) {
        cout << i << "\n";
    }
}
