// https://www.acmicpc.net/problem/1744
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
#include <vector>

int main() {
    //   logic
    int n, answer = 0;
    cin >> n;

    vector<int> plus, minus, zero;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        if (temp > 0) {
            plus.push_back(temp);
        } else if (temp < 0) {
            minus.push_back(temp);
        } else {
            zero.push_back(temp);
        }
    }

    sort(plus.begin(), plus.end());
    sort(minus.rbegin(), minus.rend());

    while (!plus.empty()) {
        if (plus.size() >= 2) {
            int mult = (plus[plus.size() - 1] * plus[plus.size() - 2]);
            int add  = (plus[plus.size() - 1] + plus[plus.size() - 2]);
            answer += max(mult, add);
            plus.pop_back();
            plus.pop_back();
        } else {
            answer += plus.back();
            plus.pop_back();
        }
    }

    while (!minus.empty()) {
        if (minus.size() >= 2) {
            answer += (minus[minus.size() - 1] * minus[minus.size() - 2]);
            minus.pop_back();
            minus.pop_back();
        } else {
            if (zero.size() == 0) {
                answer += minus.back();
            }
            minus.pop_back();
        }
    }

    cout << answer;
}
