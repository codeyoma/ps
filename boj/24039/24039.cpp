// https://www.acmicpc.net/problem/24039
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
    int n, max_bound = 20000;
    cin >> n;

    vector<bool> t(max_bound + 1, true);
    t[1] = false;
    for (int i = 2; i <= max_bound; ++i) {
        if (t[i] == false) {
            continue;
        }
        for (int j = i + i; j <= max_bound; j += i) {
            t[j] = false;
        }
    }

    int a = 2, b = 3;
    int answer = 0;
    for (int i = 4; i <= max_bound; ++i) {
        if (a * b > n) {
            cout << a * b;
            break;
        }
        if (t[i]) {
            a = b;
            b = i;
        }
    }
}
