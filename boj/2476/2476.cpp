// https://www.acmicpc.net/problem/2476
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2476/2476
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

int main() {
    fast_io();

    //   logic

    int n, answer = MIN;

    cin >> n;

    while (n--) {
        vector<int> v(6 + 1);
        int         max_dice = 0;

        for (int i = 0; i < 3; ++i) {
            int roll_dice;
            cin >> roll_dice;

            v[roll_dice]++;
            if (v[roll_dice] > v[max_dice] || (roll_dice > max_dice && v[roll_dice] == v[max_dice])) {
                max_dice = roll_dice;
            }
        }
        switch (v[max_dice]) {
            case 1: {
                answer = max(answer, max_dice * 100);
                break;
            }
            case 2: {
                answer = max(answer, max_dice * 100 + 1'000);
                break;
            }
            case 3: {
                answer = max(answer, max_dice * 1'000 + 10'000);
                break;
            }
        }
    }

    cout << answer;
}
