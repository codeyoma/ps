// https://www.acmicpc.net/problem/1021
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1021/1021
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

#include <deque>
#include <iostream>

int main() {
    //   logic
    // 양 끝단 기준으로 추정 숫자가 더 가까운 위치로 이동하기

    int n, t;

    cin >> n >> t;

    deque<int> q;
    deque<int> t_q;

    for (int i = 1; i <= n; ++i) {
        q.push_back(i);
    }

    while (t--) {
        int temp;
        cin >> temp;
        t_q.push_back(temp);
    }

    int answer = 0;

    for (const int& target: t_q) {
        int index;

        // find index
        for (int i = 0; i < q.size(); ++i) {
            if (q[i] == target) {
                index = i;
            }
        }

        if (index <= (q.size() / 2)) {
            for (int i = 0; i < index; ++i) {
                q.push_back(q.front());
                q.pop_front();
            }
            answer += index;
        } else {
            // 앞에서만 뽑을 수 있음 (q.size() - (index + 1)) 아 아닌 이유
            int reverse_index = q.size() - index;
            for (int i = 0; i < reverse_index; ++i) {
                q.push_front(q.back());
                q.pop_back();
            }
            answer += reverse_index;
        }
        q.pop_front();
    }
    cout << answer;
}
