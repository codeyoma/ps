// https://www.acmicpc.net/problem/2605
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2605/2605
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
#include <list>

int main() {
    fast_io();

    //   logic
    int n;
    cin >> n;

    list<int> l;

    for (int i = 1; i <= n; ++i) {
        int number;
        cin >> number;
        if (number == 0) {
            l.push_back(i);
        } else {
            l.insert(prev(l.end(), number), i);
        }
    }

    for (const auto& i: l) {
        cout << i << " ";
    }
}
