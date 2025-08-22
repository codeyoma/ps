// https://www.acmicpc.net/problem/1302
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1302/1302
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

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    //   logic
    int n;
    cin >> n;
    unordered_map<string, int> sell;

    for (int i = 0; i < n; ++i) {
        string book;
        cin >> book;

        sell[book]++;
    }

    string best_seller;
    int    max_count = MIN;

    for (const auto& [book, count]: sell) {
        if (count > max_count || (count == max_count && book < best_seller)) {
            best_seller = book;
            max_count   = count;
        }
    }
    cout << best_seller;
}
