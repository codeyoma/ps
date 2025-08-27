// https://www.acmicpc.net/problem/13335
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/13335/13335
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
#include <queue>

int main() {
    //   logic
    int n, w, l;
    cin >> n >> w >> l;

    queue<int> trucks;
    queue<int> bridge;
    int        time      = 0;
    int        current_l = 0;

    for (int i = 0; i < n; ++i) {
        int truck;
        cin >> truck;

        trucks.push(truck);
    }

    for (int i = 0; i < w; ++i) {
        bridge.push(0);
    }

    while (!trucks.empty() || current_l > 0) {
        current_l -= bridge.front();
        bridge.pop();

        if (!trucks.empty() && trucks.front() + current_l <= l) {
            current_l += trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
        } else {
            bridge.push(0);
        }

        time++;
    }

    cout << time;
}
