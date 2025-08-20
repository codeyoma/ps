// https://www.acmicpc.net/problem/1456
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

int main() {
    // sqrt 까지 소수를 구하고 제곱 체크
    // 소수 테이블에서 소수이면, 소수만큼 * 증가하면서 범위 테이블에 체크

    long long a, b;
    cin >> a >> b;

    long long limit = sqrt(b);

    vector<bool> t(limit + 1, true);
    t[1] = false;

    for (long long i = 2; i <= limit; ++i) {
        if (!t[i]) {
            continue;
        }
        for (long long j = i * i; j <= limit; j += i) {
            t[j] = false;
        }
    }

    long long answer = 0;

    for (long long i = 2; i <= limit; ++i) {
        if (!t[i]) {
            continue;
        }

        // for (long long s = i * i; s <= b; s *= i) {
        //     if (s <= 0) {
        //         break;
        //     }
        //     if (s >= a) {
        //         answer++;
        //     }
        // }

        long long s = i * i;
        while (s <= b) {
            if (s >= a) {
                answer++;
            }
            if (s > b / i) {
                break;
            }
            s *= i;
        }
    }

    cout << answer;
}
