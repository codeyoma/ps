// https://www.acmicpc.net/problem/21756
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/21756/21756
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
#include <list>

int main() {
    fast_io();

    //   logic
    int n;
    cin >> n;
    list<int> l;

    for (int i = 1; i <= n; ++i) {
        l.push_back(i);
    }

    while (l.size() > 1) {
        int i = l.size();
        for (auto it = l.rbegin(); it != l.rend();) {
            if (i & 1) {
                it = list<int>::reverse_iterator(l.erase(next(it).base()));
            } else {
                ++it;
            }
            i--;
        }
    }
    cout << l.front();
}
