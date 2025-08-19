// https://www.acmicpc.net/problem/4948
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
    int          max_bound = 123456 * 2;
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

    int n;
    cin >> n;
    while (n != 0) {
        int count = 0;

        for (int i = n + 1; i <= n * 2; ++i) {
            if (t[i]) {
                count++;
            }
        }
        cout << count << "\n";

        cin >> n;
    }
}
