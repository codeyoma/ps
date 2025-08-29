// https://www.acmicpc.net/problem/1946
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

int main() {
    //   logic
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<pair<int, int>> candi(n);

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            candi[i] = make_pair(a, b);
        }

        sort(candi.begin(), candi.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });

        int answer               = 0;
        int lower_than_this_rank = MAX;
        for (int i = 0; i < n; ++i) {
            if (candi[i].second < lower_than_this_rank) {
                answer++;
                lower_than_this_rank = candi[i].second;
            }
        }
        cout << answer << endl;
    }
}

#include <tuple>
void _old_solution() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<tuple<int, int>> list;
        for (int i = 0; i < N; i++) {
            int a, b;

            cin >> a >> b;

            list.push_back(make_tuple(a, b));
        }

        sort(list.begin(), list.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
            return get<0>(a) < get<0>(b);
        });

        int top_rank   = 1e8 + 7;
        int pick_count = 0;

        for (auto item: list) {
            if (get<1>(item) < top_rank) {
                pick_count++;
                top_rank = get<1>(item);
            }
        }

        cout << pick_count;
    }
}
