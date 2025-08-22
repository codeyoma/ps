// https://www.acmicpc.net/problem/24510
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/24510/24510
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

    int n;
    cin >> n;
    int max_count = MIN;

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;

        int count = 0;

        for (const auto& i: vector<string> { "for", "while" }) {
            string::size_type pos = 0;

            while ((pos = input.find(i, pos)) != string::npos) {
                count++;
                pos++;
            }
        }
        max_count = max(max_count, count);
    }
    cout << max_count << "\n";
}
