// https://www.acmicpc.net/problem/8979
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
#include <vector>

typedef struct nation {
    int number;
    int gold;
    int silver;
    int bronze;

    bool operator==(const nation& other) const {
        return gold == other.gold && silver == other.silver && bronze == other.bronze;
    }
} Nation;

template<typename T, typename Compare>
int partition(vector<T>& arr, int low, int high, Compare cmp) {
    int pivot = high;
    int left  = low - 1;

    for (int right = low; right < high; ++right) {
        if (cmp(arr[right], arr[pivot])) {
            left++;
            swap(arr[left], arr[right]);
        }
    }
    left++;
    swap(arr[left], arr[pivot]);
    return left;
}

template<typename T, typename Compare>
void q_sort(vector<T>& arr, int low, int high, Compare cmp) {
    if (low < high) {
        int pivot = partition(arr, low, high, cmp);

        q_sort(arr, low, pivot - 1, cmp);
        q_sort(arr, pivot + 1, high, cmp);
    }
}

int main() {
    //   logic

    int n, target;

    cin >> n >> target;

    vector<Nation> arr;

    for (int i = 0; i < n; ++i) {
        int number, gold, silver, bronze;

        cin >> number >> gold >> silver >> bronze;

        arr.push_back({ number, gold, silver, bronze });
    }

    q_sort(arr, 0, arr.size() - 1, [](const Nation& a, const Nation& b) {
        if (a.gold != b.gold) {
            return a.gold > b.gold;
        }

        if (a.silver != b.silver) {
            return a.silver > b.silver;
        }
        return a.bronze > b.bronze;
    });

    int    rank        = 1;
    Nation rank_before = arr.front();

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            if (!(arr[i] == rank_before)) {
                rank        = i + 1;
                rank_before = arr[i];
            }
        }

        if (arr[i].number == target) {
            cout << rank << "\n";
            break;
        }
    }
}
