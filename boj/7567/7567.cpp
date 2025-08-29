// https://www.acmicpc.net/problem/7567
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/7567/7567
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
#include <string>

typedef enum class dir {
    Start,
    Up,
    Down
} Dir;

int main() {
    fast_io();

    //   logic
    string dishes;
    cin >> dishes;

    int answer = 0;
    Dir d      = Dir::Start;

    for (const char& dish: dishes) {
        if (dish == '(') {
            if (d == Dir::Up) {
                answer += 5;
            } else {
                answer += 10;
            }
            d = Dir::Up;
        } else {
            if (d == Dir::Down) {
                answer += 5;
            } else {
                answer += 10;
            }
            d = Dir::Down;
        }
    }

    cout << answer;
}
