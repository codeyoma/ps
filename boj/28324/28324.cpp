// https://www.acmicpc.net/problem/28324
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
    int n;
    cin >> n;
    vector<long long> p(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    long long answer       = 0;
    long long before_value = 0;

    for (int i = n - 1; i >= 0; i--) {
        LOG << i << ": " << before_value << "\n";
        before_value = min(before_value + 1, p[i]);
        answer += before_value;
    }
    LOG << answer << endl;
    cout << answer << endl;
    return 0;
}
