// https://www.acmicpc.net/problem/14469
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/14469/14469
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

    vector<vector<int>> c(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        int a, t;

        cin >> a >> t;
        c[i][0] = a;
        c[i][1] = t;
    }

    sort(c.begin(), c.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    for (const auto& i: c) {
        for (const auto& j: i) {
            LOG << j << " ";
        }
        LOG << endl;
    }

    int time = 0;

    for (const auto& i: c) {
        if (time < i[0]) {
            time += i[0] - time;
        }
        time += i[1];
    }
    cout << time;
}