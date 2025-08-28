// https://www.acmicpc.net/problem/11003
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11003/11003
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
    //   logic
    int n, l;
    cin >> n >> l;

    int         cur_min, can_min;
    vector<int> v(n + 1);
    v[0] = MAX;

    for (int i = 0; i < n; ++i) {
        cin >> v[i + 1];
    }

    cur_min = 0;
    can_min = 0;
    for (int i = 0; i < n; ++i) {
        if (v[cur_min] > v[i]) {
            cur_min = i;
        }

        if (can_min != cur_min && v[can_min] > v[i]) {
            can_min = i;
        }

        cout << v[cur_min] << " ";
    }
}
