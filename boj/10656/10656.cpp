// https://www.acmicpc.net/problem/10656
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10656/10656
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
#include <string>
#include <vector>

struct coor {
    int x;
    int y;
};

int main() {
    fast_io();

    //   logic
    int n, m;
    cin >> n >> m;

    vector<string> p(n);
    vector<coor>   answer;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (const auto& i: p) {
        LOG << i << "\n";
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            // 좌우 - 전칸 막혀있고, 뒤에 2개 이상
            // 상하 - 위에 막혀있고, 아래로 2개 이상
            {
                if (c - 1 < 0 || p[r][c - 1] == '#') {
                    int i = 0;
                    while (c + i < m) {
                        if (p[r][c + i] == '.') {
                            ++i;
                        } else {
                            break;
                        }
                    }

                    if (i >= 3) {
                        LOG << r + 1 << " " << c + 1 << "\n";
                        answer.push_back({ r + 1, c + 1 });
                    }
                }
            }

            {
                if (r - 1 < 0 || p[r - 1][c] == '#') {
                    int i = 0;
                    while (r + i < n) {
                        if (p[r + i][c] == '.') {
                            ++i;
                        } else {
                            break;
                        }
                    }

                    if (i >= 3) {
                        if (!(!answer.empty() && answer.back().x == r + 1 && answer.back().y == c + 1)) {
                            answer.push_back({ r + 1, c + 1 });
                        }
                    }
                }
            }
        }
    }

    cout << answer.size() << "\n";
    for (const auto& c: answer) {
        cout << c.x << " " << c.y << "\n";
    }
}
