// https://www.acmicpc.net/problem/23739
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/23739/23739
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
    int n, answer = 0;
    int remain_study_time = 30;

    cin >> n;

    while (n--) {
        int chapter;

        cin >> chapter;

        // chapter 시간이 홀수일떄 대비해서 +1 해주기 (/2하면 절반 값 이상이 됨)
        if (remain_study_time >= chapter || (chapter + 1) / 2 <= remain_study_time) {
            answer++;
        }

        remain_study_time -= chapter;

        if (remain_study_time <= 0) {
            remain_study_time = 30;
        }
    }
    cout << answer;
}
