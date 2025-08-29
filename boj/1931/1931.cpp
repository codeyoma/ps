// https://www.acmicpc.net/problem/1931
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
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        meetings[i] = make_pair(start, end);
    }

    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
            // 끝나는 시간이 같다면, 시작 시간이 느릴수록 유리한거 아닌가?
            // return a.first > b.first;
            // 영향을 끼치지 않으나, 정렬 안정성을 위해 < 가 낫다
        }
        return a.second < b.second;
    });
    int answer        = 0;
    int last_end_time = 0;

    // for(const auto& [start, end]: meetings){}
    for (int i = 0; i < n; ++i) {
        int start_time = meetings[i].first;
        int end_time   = meetings[i].second;
        LOG << start_time << " " << end_time << endl;

        if (last_end_time <= start_time) {
            answer++;
            last_end_time = end_time;
        }
    }
    cout << answer;
}

//--------------------------------------------------------------------------------------------------
struct coor {
    int  sx;
    int  ex;
    bool operator<(const coor& other) const {
        if (ex == other.ex) {
            return sx < other.sx;
        }
        return ex < other.ex;
    }
};

void _old_solution() {
    int n;
    cin >> n;
    vector<coor> meetings;

    while (n--) {
        int sx, ex;
        cin >> sx >> ex;
        meetings.push_back({ sx, ex });
    }
    sort(meetings.begin(), meetings.end());

    int end_time = -1;
    int answer   = 0;

    for (const auto& [start, end]: meetings) {
        if (start >= end_time) {
            ++answer;
            end_time = end;
        }
    }

    cout << answer;
}
