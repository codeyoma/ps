// https://www.acmicpc.net/problem/10250
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10250/10250
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

int main() {
    fast_io();

    //   logic
    // 왼쪽열의 아래부터 채워지는 형태
    // 몫과 나머지로 가능

    int t;
    cin >> t;

    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;

        int f = n % h ? n % h : h;
        int c = ((n - 1) / h) + 1;

        cout << f << ((c < 10) ? "0" : "") << c << "\n";
    }
}
