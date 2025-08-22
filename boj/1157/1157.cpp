// https://www.acmicpc.net/problem/1157
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1157/1157
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
    string input;
    cin >> input;

    vector<int> list('z' - 'a' + 1);

    int  max_count = MIN;
    int  max_pos   = -1;
    bool dup_check = false;

    for (int i = 0; i < input.length(); ++i) {
        int c = input[i] <= 'Z' ? input[i] - 'A' : input[i] - 'a';
        list[c]++;

        if (list[c] > max_count) {
            max_count = list[c];
            dup_check = false;
            max_pos   = c;
        } else if (list[c] == max_count) {
            dup_check = true;
        }
    }

    if (dup_check) {
        cout << "?";
    } else {
        cout << static_cast<char>('A' + max_pos);
    }
}
