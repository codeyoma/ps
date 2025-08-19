// https://www.acmicpc.net/problem/25379
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

#include <algorithm>
#include <iostream>

int main() {
    //   logic
    int n;

    cin >> n;

    // int > long long으로 바꿨더니 해결됨
    long long count_odd_case  = 0;
    long long odd_pointer     = 0;
    long long count_even_case = 0;
    long long even_pointer    = 0;

    for (int i = 0; i < n; ++i) {
        long long temp;
        cin >> temp;
        if (temp & 1) {
            count_odd_case += abs(i - odd_pointer);
            odd_pointer++;
        } else {
            count_even_case += abs(i - even_pointer);
            even_pointer++;
        }
    }

    cout << min(count_even_case, count_odd_case);
}
