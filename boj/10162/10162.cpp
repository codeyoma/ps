// https://www.acmicpc.net/problem/10162
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10162/10162
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

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <vector>

int main() {
    vector<int> timer = { 300, 60, 10 };
    vector<int> push_count(3, 0);

    int t;
    cin >> t;

    for (size_t i = 0; i < timer.size(); ++i) {
        push_count[i] = t / timer[i];
        t %= timer[i];
    }

    if (t) {
        cout << -1;
    } else {
        cout << push_count[0] << " " << push_count[1] << " " << push_count[2];
    }
}