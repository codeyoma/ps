// https://www.acmicpc.net/problem/1769
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1769/1769
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

int main() {
    //   logic
    string input;
    int    count = 0;
    cin >> input;

    while (input.length() > 1) {
        int sum = 0;

        for (const char& c: input) {
            sum += c - '0';
        }
        input = to_string(sum);

        count++;
    }

    cout << count << '\n';
    if ((input.front() - '0') % 3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
