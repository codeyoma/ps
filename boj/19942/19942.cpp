// https://www.acmicpc.net/problem/19942
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
#include <cstring>
#include <vector>

using namespace std;

int         N;
int         Con[4];
int         Ing[15][5];
int         minPrice = 15 * 500;
vector<int> bestChoice;

void backtracking(int sum[5], vector<int> choice, int idx) {
    for (int i = 0; i < 4; i++) {
        if (sum[i] < Con[i]) {
            return;
        }
    }
    if (minPrice > sum[4] || (minPrice == sum[4] && choice < bestChoice)) {
        minPrice   = sum[4];
        bestChoice = choice;
    }
    for (int i = idx; i < N; i++) {
        int         newsum[5];
        vector<int> newchoice = choice;
        memcpy(newsum, sum, sizeof(int) * 5);
        newchoice.push_back(i + 1);
        for (int j = 0; j < 5; j++) {
            newsum[j] -= Ing[i][j];
        }
        backtracking(newsum, newchoice, i + 1);
    }
}

int main() {
    fast_io();
    int sum[5] = {
        0,
    };

    cin >> N;

    for (int i = 0; i < 4; i++) {
        cin >> Con[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            int input;
            cin >> input;
            Ing[i][j] = input;
            sum[j] += input;
        }
    }
    vector<int> choice;

    backtracking(sum, choice, 0);
    cout << minPrice << "\n";
    int idx = 0;
    for (int i = 1; i <= N; i++) {
        if (idx < bestChoice.size() && i == bestChoice[idx]) {
            idx++;
        } else {
            cout << i << " ";
        }
    }
}