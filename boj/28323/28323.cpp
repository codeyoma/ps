// https://www.acmicpc.net/problem/28323
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/28323/28323
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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int  odd_start_cnt  = 0;
    int  even_start_cnt = 0;
    bool is_odd         = true;
    bool is_even        = true;

    for (const auto& i: v) {
        if (i & 1) {
            if (is_odd) {
                odd_start_cnt++;
                is_odd = !is_odd;
            }

            if (!is_even) {
                even_start_cnt++;
                is_even = !is_even;
            }

        } else {
            if (!is_odd) {
                odd_start_cnt++;
                is_odd = !is_odd;
            }

            if (is_even) {
                even_start_cnt++;
                is_even = !is_even;
            }
        }
    }

    cout << max(odd_start_cnt, even_start_cnt);
}

void _old_solution() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int  max_cnt = MIN;
    bool is_odd  = true;
    int  cnt     = 0;

    for (const auto& i: v) {
        if (i & 1) {
            if (is_odd) {
                cnt++;
                is_odd = !is_odd;
            }
        } else {
            if (!is_odd) {
                cnt++;
                is_odd = !is_odd;
            }
        }
    }

    max_cnt = max(cnt, max_cnt);
    cnt     = 0;
    is_odd  = false;

    for (const auto& i: v) {
        if ((i & 1) == 0) {
            if (!is_odd) {
                cnt++;
                is_odd = !is_odd;
            }
        } else {
            if (is_odd) {
                cnt++;
                is_odd = !is_odd;
            }
        }
    }

    max_cnt = max(cnt, max_cnt);

    cout << max_cnt;
}