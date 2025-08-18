// https://www.acmicpc.net/problem/19941
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
#include <string>
#include <vector>

int main() {
    int    n, k, answer = 0;
    string bench;

    cin >> n >> k >> bench;
    vector<int> p_pos, h_pos;

    for (int i = 0; i < bench.length(); ++i) {
        if (bench[i] == 'H') {
            h_pos.push_back(i);
        } else if (bench[i] == 'P') {
            p_pos.push_back(i);
        }
    }

    int p_i = 0;
    int h_i = 0;

    while (p_i < p_pos.size() && h_i < h_pos.size()) {
        if (abs(h_pos[h_i] - p_pos[p_i]) <= k) {
            answer++;
            h_i++;
            p_i++;
        } else if (h_pos[h_i] < p_pos[p_i]) {
            h_i++;
        } else {
            p_i++;
        }
    }
    cout << answer;
}

int _solve_greedy() {
    //   logic
    int    n, k, answer = 0;
    string bench;

    cin >> n >> k >> bench;

    for (int i = 0; i < bench.length(); ++i) {
        if (bench[i] == 'P') {
            for (int j = -k; j <= k; ++j) {
                if (j == 0) {
                    continue;
                }
                if (i + j >= 0 && (i + j) < bench.length()) {
                    if (bench[i + j] == 'H') {
                        answer++;
                        bench[i + j] = 'X';
                        break;
                    }
                }
            }
        }
    }

    cout << answer;
}
