// https://www.acmicpc.net/problem/11652
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11652/11652
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

int main() {
    //   logic
    int n;
    cin >> n;

    unordered_map<long long, int> dup_check;

    for (int i = 0; i < n; ++i) {
        long long number;
        cin >> number;
        dup_check[number]++;
    }
    {
        vector<pair<long long, int>> arr(dup_check.begin(), dup_check.end());

        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        cout << arr.front().first;
    }

    // {
    // 	long long answer_number;
    // 	int       max_count = MIN;
    // 	for (const auto& [number, count]: dup_check) {
    // 		if (max_count < count || (max_count == count && number < answer_number)) {
    // 			max_count     = count;
    // 			answer_number = number;
    // 		}
    // 	}
    // 	cout << answer_number;
    // }
}
