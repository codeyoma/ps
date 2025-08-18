// https://www.acmicpc.net/problem/1449
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
#include <vector>

int main() {
    int n, l;
    cin >> n >> l;
    int pipe_size = 1001;

    vector<bool> pipe(pipe_size, true);
    int          count = 0;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;

        pipe[temp] = false;
    }

    for (int i = 0; i < pipe_size; ++i) {
        if (pipe[i] == false) {
            count++;
            for (int j = 0; j < l; ++j) {
                pipe[i + j] = true;
            }
        }
    }
    cout << count;
    return 0;
}
