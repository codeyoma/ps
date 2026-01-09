// https://www.acmicpc.net/problem/33735
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

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

int count(const vector<string>& canvas, int n, int r, int c) {
    int cnt    = 0;
    int answer = 0;
    int dr[4]  = { r, n - r - 1, r, n - r - 1 };
    int dc[4]  = { c, c, n - c - 1, n - c - 1 };

    for (int i = 0; i < 4; ++i) {
        int nr = dr[i];
        int nc = dc[i];

        if (canvas[nr][nc] == '#') {
            cnt++;
        }
    }

    if (cnt == 2) {
        answer += 2;
    } else if (cnt == 1 || cnt == 3) {
        answer += 1;
    }

    return answer;
}

int main() {
    fast_io();

    //   logic

    int n, u;

    cin >> n >> u;

    vector<string> canvas(n);

    for (int i = 0; i < n; ++i) {
        cin >> canvas[i];
    }

    int answer = 0;

    for (int r = 0; r < n / 2; ++r) {
        for (int c = n / 2; c < n; ++c) {
            answer += count(canvas, n, r, c);
        }
    }

    cout << answer << "\n";

    for (int i = 0; i < u; ++i) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;

        int before_cnt = count(canvas, n, r, c);

        if (canvas[r][c] == '#') {
            canvas[r][c] = '.';
        } else {
            canvas[r][c] = '#';
        }

        int after_cnt = count(canvas, n, r, c);

        if (after_cnt > before_cnt) {
            answer++;
        } else if (before_cnt > after_cnt) {
            answer--;
        }

        cout << answer << "\n";
    }
}
