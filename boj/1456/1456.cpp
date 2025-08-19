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

#include <iostream>
#include <vector>

int main() {
    //   logic
    int a, b, answer = 0;
    cin >> a >> b;
    vector<bool> t(b + 1, true), a_t(b + 1, false);
    t[1] = false;

    for (int i = 2; i <= b; ++i) {
        if (t[i] == false) {
            continue;
        }

        for (int j = i + i; j <= b; j += i) {
            t[i] = false;
        }

        for (int j = i * i; j <= b; j *= i) {
            if (a_t[j] == false) {
                a_t[j] = true;
                answer++;
            }
        }
    }

    cout << answer;
}
