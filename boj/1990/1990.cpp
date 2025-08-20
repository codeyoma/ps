// https://www.acmicpc.net/problem/1990
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

#include <cmath>
#include <iostream>
#include <vector>

bool is_palin(int origin) {
    int rev = 0, a = origin;

    while (a > 0) {
        rev = rev * 10 + a % 10;
        a /= 10;
    }

    return rev == origin;

    // too slow
    // {
    //     string number   = to_string(a);
    //     string r_number = to_string(a);
    //     reverse(r_number.begin(), r_number.end());
    //     return number == r_number;
    // }
}

int main() {
    //   logic

    int a, b;
    cin >> a >> b;

    vector<bool> t(b + 1, true);
    t[1] = false;

    for (int i = 2; i <= sqrt(b); ++i) {
        if (!t[i]) {
            continue;
        }
        for (int j = i * i; j <= b; j += i) {
            t[j] = false;
        }
    }

    for (int i = a; i <= b; i++) {
        if (!t[i]) {
            continue;
        }
        if (is_palin(i)) {
            cout << i << "\n";
        }
    }
    cout << -1;
}
