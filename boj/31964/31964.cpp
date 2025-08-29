// https://www.acmicpc.net/problem/31964
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
    long long n, answer = 0, x_pos = 0;
    cin >> n;

    vector<long long> x(n, 0), t(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        long long dist = abs(x[i] - x_pos);
        if (t[i] > answer) {
            dist = max(dist, t[i] - answer);
        }
        answer += dist;
        x_pos = x[i];
    }

    answer += x_pos;

    cout << answer;
}

int _old_solution() {
    //   logic
    long long n, answer = 0, x_pos = 0;
    cin >> n;

    vector<long long> x(n, 0);
    vector<long long> t(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        if (t[i] <= answer) {
            answer += abs(x_pos - x[i]);
            x_pos = x[i];
            continue;
        }
        answer += max(abs(x_pos - x[i]), abs(t[i] - answer));
        x_pos = x[i];
    }

    answer += x_pos;

    cout << answer;
}
