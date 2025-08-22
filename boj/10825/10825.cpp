// https://www.acmicpc.net/problem/10825
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/10825/10825
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

typedef struct student {
    string name;
    int    k;
    int    e;
    int    m;
} Student;

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

    vector<Student> arr;

    for (int i = 0; i < n; ++i) {
        string name;
        int    k, e, m;
        cin >> name >> k >> e >> m;

        arr.push_back({ name, k, e, m });
    }

    q_sort(arr, 0, arr.size() - 1, [](const Student& a, const Student& b) {
        if (a.k != b.k) {
            return a.k > b.k;
        }

        if (a.e != b.e) {
            return a.e < b.e;
        }

        if (a.m != b.m) {
            return a.m > b.m;
        }

        return a.name < b.name;
    });

    for (const auto& i: arr) {
        cout << i.name << "\n";
    }
}
