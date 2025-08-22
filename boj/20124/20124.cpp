// https://www.acmicpc.net/problem/20124
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
#include <string>
#include <vector>

typedef struct candi {
    int    score;
    string name;

} Candi;

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
    int n;
    cin >> n;
    vector<Candi> arr;

    for (int i = 0; i < n; ++i) {
        string name;
        int    score;

        cin >> name >> score;

        arr.push_back({ score, name });
    }

    q_sort(arr, 0, arr.size() - 1, [](const Candi& a, const Candi& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.name < b.name;
    });

    cout << arr.front().name;
}
