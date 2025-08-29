// https://www.acmicpc.net/problem/14467
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/14467/14467
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
#include <vector>

typedef enum class status {
    START,
    LEFT,
    RIGHT
} Status;

int main() {
    fast_io();

    //   logic
    int n, answer = 0;
    cin >> n;

    vector<Status> cows(n + 1, Status::START);

    while (n--) {
        int cow, side;
        cin >> cow >> side;
        Status s = side ? Status::RIGHT : Status::LEFT;

        if (cows[cow] != Status::START && cows[cow] != s) {
            answer++;
        }
        cows[cow] = s;
    }
    cout << answer;
}
