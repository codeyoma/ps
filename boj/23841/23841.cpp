// https://www.acmicpc.net/problem/23841
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/23841/23841
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
    int n, m;
    cin >> n >> m;

    vector<string> arr;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;

        arr.push_back(input);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == '.') {
                continue;
            }

            arr[i][m - 1 - j] = arr[i][j];
        }
        cout << arr[i] << "\n";
    }
}
