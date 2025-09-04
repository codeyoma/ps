// https://www.acmicpc.net/problem/17619
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/17619/17619
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <algorithm>
#include <iostream>

typedef struct log {
    int s_x;
    int e_x;
    int index;
} log_t;

bool is_cross(const log_t& a, const log_t& b) {
    if ((b.s_x <= a.e_x && a.e_x <= b.e_x) || (a.s_x <= b.e_x && b.e_x <= a.e_x)) {
        return true;
    }

    return false;
}

int find(vector<int>& root, const int& nidle) {
    if (root[nidle] == nidle) {
        return nidle;
    }

    root[nidle] = find(root, root[nidle]);

    return root[nidle];
}

bool union_set(vector<int>& root, const int& a, const int& b) {
    int root_a = find(root, a);
    int root_b = find(root, b);

    if (root_a == root_b) {
        return false;
    }
    LOG << "in - union_set " << root_a << " " << root_b << "\n";

    if (a > b) {
        root[root_a] = root_b;
    } else {
        root[root_b] = root_a;
    }

    return true;
}

int main() {
    fast_io();

    //   logic

    // s_x 낮은 순으로 정렬
    // union-find
    //  좌표가 겹치면 index가 낮은 것을 부모로 갖기
    // 겹친다면
    //  시작점, 끝점 업데이트 하기
    //  a, b 둘다

    int n, q;
    cin >> n >> q;

    vector<log_t> v(n);
    vector<int>   root(n + 1);

    for (int i = 0; i < n; ++i) {
        int s_x, e_x, y;
        cin >> s_x >> e_x >> y;
        v[i]        = { s_x, e_x, i + 1 };
        root[i + 1] = i + 1;
    }

    sort(v.begin(), v.end(), [](const log_t& a, const log_t& b) {
        if (a.s_x == b.s_x) {
            return a.e_x < b.e_x;
        }

        if (a.e_x == b.e_x) {
            return a.index < b.index;
        }

        return a.s_x < b.s_x;
    });

    // solution 1
    // union-find
    /*

    for (int i = 0; i < n - 1; ++i) {
        if (is_cross(v[i], v[i + 1])) {
            LOG << "!!\n";
            log_t temp_log;

            temp_log.index = v[i].index;
            temp_log.s_x   = v[i].s_x > v[i + 1].s_x ? v[i + 1].s_x : v[i].s_x;
            temp_log.e_x   = v[i].e_x > v[i + 1].e_x ? v[i].e_x : v[i + 1].e_x;

            union_set(root, v[i].index, v[i + 1].index);

            v[i + 1] = temp_log;
        }
    }

    for (const auto& a: v) {
        LOG << a.s_x << " " << a.e_x << "\n";
    }

    for (const auto& a: root) {
        LOG << a << "\n";
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (find(root, a) == find(root, b)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    */

    // solution 2
    // sweep
    int current_group   = 0;
    int current_max_x_e = -1;

    for (const auto& l: v) {
        if (current_max_x_e < l.s_x) {
            current_group++;
            current_max_x_e = l.e_x;
        } else {
            current_max_x_e = max(current_max_x_e, l.e_x);
        }

        root[l.index] = current_group;
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (root[a] == root[b]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}