#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    static int total[20];
    static int potential_correct[20][20];
    static int potential_correct_exclude[20][20][20];

    for (int i = 0; i < K; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;

        total[x]++;
        potential_correct[x][y]++;
        potential_correct[x][z]++;
        potential_correct_exclude[x][y][z]++;
        potential_correct_exclude[x][z][y]++;
    }

    int maxScore = 0;
    int ways     = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        int score = 0;

        for (int x = 0; x < N; x++) {
            if (!(mask & (1 << x))) {
                continue;
            }

            int broken = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    broken += potential_correct[x][i];
                }
            }

            for (int i = 0; i < N; i++) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                for (int j = i + 1; j < N; j++) {
                    if (mask & (1 << j)) {
                        broken -= potential_correct_exclude[x][i][j];
                    }
                }
            }

            score += total[x] - broken;
        }

        if (score > maxScore) {
            maxScore = score;
            ways     = 1;
        } else if (score == maxScore) {
            ways++;
        }
    }

    cout << maxScore << " " << ways << "\n";
    return 0;
}