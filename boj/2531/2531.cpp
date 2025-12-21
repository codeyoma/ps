// https://www.acmicpc.net/problem/2531
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

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    fast_io();

    //   logic
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
    }

    int l = 0, r = k;
    int answer = 0;

    unordered_map<int, int> cnt;

    for (int i = 0; i < k; ++i) {
        cnt[sushi[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        int cur = cnt.size() + (cnt.count(c) ? 0 : 1);
        answer  = max(answer, cur);

        if (--cnt[sushi[i]] == 0) {
            cnt.erase(sushi[i]);
        }

        cnt[sushi[(i + k) % n]]++;
    }

    cout << answer;
}
