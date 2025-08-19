// https://www.acmicpc.net/problem/13305
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
    int n;
    cin >> n;

    vector<long long> dist(n - 1), gas(n);

    for (int i = 0; i < n - 1; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> gas[i];
    }

    long long answer        = 0;
    long long current_price = MAX;

    for (int i = 0; i < n - 1; ++i) {
        current_price = min(current_price, gas[i]);
        answer += dist[i] * current_price;
    }
    cout << answer;
}
