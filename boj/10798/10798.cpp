// https://www.acmicpc.net/problem/10798
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10798/10798
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
#include <string>
#include <vector>

int main() {
    //   logic

    int            n = 5, max_len = 0;
    vector<string> list;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;

        list.push_back(temp);
        if (max_len < temp.length()) {
            max_len = temp.length();
        }
    }

    for (int i = 0; i < max_len; ++i) {
        for (int j = 0; j < n; ++j) {
            if (list[j].length() - 1 < i) {
                continue;
            }
            cout << list[j][i];
        }
    }
}
