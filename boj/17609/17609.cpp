// https://www.acmicpc.net/problem/17609
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/17609/17609
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

bool is_palindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int solve_case(const string& s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (is_palindrome(s, l + 1, r) || is_palindrome(s, l, r - 1)) {
                return 1;
            }
            return 2;
        }
    }

    return 0;
}

int main() {
    //   logic
    int n;
    cin >> n;

    while (n--) {
        string input;
        cin >> input;

        cout << solve_case(input) << "\n";
    }
}
