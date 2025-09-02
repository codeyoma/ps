// https://www.acmicpc.net/problem/10164
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10164/10164
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

int count_path(int start_row, int start_col, int end_row, int end_col) {
    int row_size = end_row - start_row + 1;
    int col_size = end_col - start_col + 1;

    vector<vector<int>> table(row_size, vector<int>(col_size, 1));

    for (int r = 1; r < row_size; ++r) {
        for (int c = 1; c < col_size; ++c) {
            table[r][c] = table[r - 1][c] + table[r][c - 1];
        }
    }

    return table[row_size - 1][col_size - 1];
}

int main() {
    fast_io();

    //   logic

    int n, m, k;
    cin >> n >> m >> k;

    if (k == 0) {
        cout << count_path(0, 0, n - 1, m - 1);
    } else {
        int row_k = (k - 1) / m;
        int col_k = (k - 1) % m;
        cout << count_path(0, 0, row_k, col_k) * count_path(row_k, col_k, n - 1, m - 1);
    }
}
