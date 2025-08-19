// https://www.acmicpc.net/problem/28325
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //   logic
    long long n, input, answer = 0;
    long long first_zero_count = 0, last_zero_count = 0;
    bool      first_zero = true, last_zero = false;
    cin >> n;

    // 처음 과 마지막 이어지는 0구간을 따로 세서 최대로 해야함 ((n + 1) / 2) 만큼 추가)
    for (long long i = 0; i < n; ++i) {
        cin >> input;
        if (input == 0) {
            if (first_zero) {
                first_zero_count++;
            } else {
                last_zero_count++;
                last_zero = true;
            }
        } else {
            answer += (last_zero_count + 1) / 2;
            first_zero      = false;
            last_zero       = false;
            last_zero_count = 0;
            answer += input;
        }
    }

    if (last_zero) {
        answer += (first_zero_count + last_zero_count + 1) / 2;
    } else {
        if (answer == 0) {
            answer += (first_zero_count) / 2;
        } else {
            answer += (first_zero_count + 1) / 2;
        }
    }

    cout << answer;
}
