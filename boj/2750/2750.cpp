// https://www.acmicpc.net/problem/2750
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

// lomuto partitoin
int lomuto_partition(vector<int>& arr, int low, int high) {
    int pivot      = arr[high];
    int left_index = low - 1;

    for (int right_index = low; right_index < high; ++right_index) {
        if (arr[right_index] <= pivot) {
            left_index++;
            swap(arr[left_index], arr[right_index]);
        }
    }
    swap(arr[left_index + 1], arr[high]);
    return left_index + 1;
}

void lomuto_q_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = lomuto_partition(arr, low, high);

        lomuto_q_sort(arr, low, pivot_index - 1);
        lomuto_q_sort(arr, pivot_index + 1, high);
    }
}

// naive
vector<int> naive_q_sort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int         pivot = arr.back();
    vector<int> left, middle, right;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < pivot) {
            left.push_back(arr[i]);
        } else if (arr[i] > pivot) {
            right.push_back(arr[i]);
        } else {
            middle.push_back(arr[i]);
        }
    }

    left  = naive_q_sort(left);
    right = naive_q_sort(right);

    vector<int> result;
    result.reserve(left.size() + middle.size() + right.size());

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), middle.begin(), middle.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int main() {
    //   logic
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // lomuto_q_sort(arr, 0, n - 1);
    arr = naive_q_sort(arr);

    for (const auto& i: arr) {
        cout << i << "\n";
    }
}
