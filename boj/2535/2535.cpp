// https://www.acmicpc.net/problem/2535
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

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

typedef struct player {
    int nation;
    int student;
    int score;

    bool operator<=(const player& p2) const {
        return score > p2.score;
    }
} Player;

int partition(vector<Player>& a, int l, int h) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; ++right) {
        if (a[right] <= a[p]) {
            left++;
            swap(a[left], a[right]);
        }
    }
    left++;
    swap(a[left], a[p]);
    return left;
}

void qsort(vector<Player>& a, int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);

        qsort(a, l, p - 1);
        qsort(a, p + 1, h);
    }
}

int main() {
    //   logic
    int n;

    cin >> n;

    vector<Player> arr(n);

    for (int i = 0; i < n; ++i) {
        int nation, student, score;
        cin >> nation >> student >> score;

        arr[i] = Player { nation, student, score };
    }

    qsort(arr, 0, n - 1);

    unordered_map<int, int> dup_check;

    int limit = 0;
    for (const auto& [nation, student, score]: arr) {
        dup_check[nation]++;
        limit++;
        if (dup_check.at(nation) > 2) {
            dup_check[nation]--;
            limit--;
        } else {
            cout << nation << " " << student << "\n";
        }

        if (limit == 3) {
            break;
        }
    }
}
