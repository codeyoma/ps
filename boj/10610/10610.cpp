// https://www.acmicpc.net/problem/10610
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

int partition(vector<int>& a, int l, int h) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; ++right) {
        if (a[right] > a[p]) {
            left++;
            swap(a[left], a[right]);
        }
    }
    left++;
    swap(a[left], a[p]);
    return left;
}

void sort(vector<int>& a, int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);

        sort(a, l, p - 1);
        sort(a, p + 1, h);
    }
}

int main() {
    //   logic
    string input;

    cin >> input;

    vector<int> arr;

    long long check_sum = 0;
    bool      has_zero  = false;

    for (size_t i = 0; i < input.size(); ++i) {
        int temp_num = input[i] - '0';
        check_sum += (temp_num);
        arr.push_back(temp_num);
        if (temp_num == 0) {
            has_zero = true;
        }
    }
    if (!has_zero || check_sum % 3 != 0) {
        LOG << check_sum;
        cout << -1;
    } else {
        sort(arr, 0, arr.size() - 1);
        for (const auto& i: arr) {
            cout << i;
        }
    }
}
