// https://www.acmicpc.net/problem/10570
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10570/10570
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
    int t;
    cin >> t;
    while (t--) {
        int         n;
        vector<int> v(1001);

        cin >> n;

        int answer  = MAX;
        int a_count = 0;
        while (n--) {
            int temp;
            cin >> temp;
            v[temp]++;

            if (v[temp] > a_count || (temp < answer && v[temp] == a_count)) {
                answer  = temp;
                a_count = v[temp];
            }
        }

        cout << answer << "\n";
    }
}
