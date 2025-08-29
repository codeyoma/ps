// https://www.acmicpc.net/problem/11003
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11003/11003
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

#include <deque>
#include <iostream>
#include <vector>

int main() {
    //   logic
    fast_io(); // <- 없으면 시간 초과

    int n, l;
    cin >> n >> l;

    vector<int> v(n + 1);
    deque<int>  q;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    // solution 1
    // min-heap으로 이동하면서 최소값 출력
    // O(n log n)

    // solution 2
    // deque로 최소값 인덱스 업데이트 방식
    // O(n)
    // 각 요소 순회하면서
    // l 이내의 인덱스 최소값 찾기
    // - deque는 인덱스 값
    // - deque로 어느 값이든 push_back() 하면서
    // - deque back 요소보다 작다면 pop_back()하면서, 작은 값 알맞은 위치에 넣기
    // - - 순서상 뒤에서 작은게 나오면 해당 값이 구간의 현재 작은 값 확정
    // - - 순서상 뒤에서 큰게 나오면 해당 값은 구간의 잠재적 작은 값
    // - deque front 요소가 현재 가장 작은 값
    // - - 하지만 deque front의 인덱스가 l 이전 범위를 넘었다면 pop_front();
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && v[q.back()] > v[i]) {
            q.pop_back();
        }

        q.push_back(i);

        while (!q.empty() && (i - q.front()) >= l) {
            q.pop_front();
        }

        cout << v[q.front()] << " ";
    }
}
