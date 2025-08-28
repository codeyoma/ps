// https://www.acmicpc.net/problem/17298
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/17298/17298
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
#include <stack>
#include <vector>

typedef struct nge_type {
    int number;
    int sequence;
} NGE_TYPE;

int main() {
    //   logic
    int n;
    cin >> n;
    vector<int>     nge(n + 1, -1);
    stack<NGE_TYPE> s;

    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;

        while (!s.empty() && s.top().number < temp) {
            nge[s.top().sequence] = temp;
            s.pop();
        }
        s.push({ temp, i });
    }

    for (int i = 1; i <= n; ++i) {
        cout << nge[i] << " ";
    }
}
