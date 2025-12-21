// https://www.acmicpc.net/problem/21758
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

    int n;
    cin >> n;

    vector<int> honey(n, 0);
    vector<int> psum(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> honey[i];
    }

    psum[0] = honey[0];

    for (int i = 1; i < n; ++i) {
        psum[i] = psum[i - 1] + honey[i];
    }

    int answer = MIN;

    for (int right = 1; right < n - 1; ++right) {
        int left = psum[n - 1] - honey[0] - honey[right];

        answer = max(answer, left + (psum[n - 1] - psum[right]));
    }

    for (int left = 1; left < n - 1; ++left) {
        int right = psum[n - 1] - honey[n - 1] - honey[left];

        answer = max(answer, right + (psum[left] - honey[left]));
    }

    for (int pot = 1; pot < n - 1; ++pot) {
        int left  = psum[pot] - psum[0];
        int right = psum[n - 2] - psum[pot - 1];

        answer = max(answer, left + right);
    }

    LOG << answer;
    cout << answer;
}
