// https://www.acmicpc.net/problem/1439
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1439/1439
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

int main() {
    fast_io();
    string s;

    cin >> s;

    int one_place  = 0;
    int zero_place = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        if (i == 0) {
            if (s[i] == '0') {
                zero_place++;
            } else {
                one_place++;
            }
        } else {
            if (s[i] != s[i - 1]) {
                if (s[i] == '0') {
                    zero_place++;
                } else {
                    one_place++;
                }
            }
        }
    }

    cout << min(one_place, zero_place);
}