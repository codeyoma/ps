// https://www.acmicpc.net/problem/1296
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

template<typename T, typename Compare>
int partition(vector<T>& a, int l, int h, Compare cmp) {
    int p    = h;
    int left = l - 1;

    for (int right = l; right < h; right++) {
        if (cmp(a[right], a[p])) {
            left++;
            swap(a[left], a[right]);
        }
    }
    left++;
    swap(a[left], a[p]);
    return left;
}

template<typename T, typename Compare>
void q_sort(vector<T>& a, int l, int h, Compare cmp) {
    if (l < h) {
        int p = partition(a, l, h, cmp);
        q_sort(a, l, p - 1, cmp);
        q_sort(a, p + 1, h, cmp);
    }
}

typedef struct winning_name {
    string    name;
    long long score;
} Winning_Name;

int main() {
    //   logic
    // 이름 들어올때 바로 값 판별해서 최대 값 업데이트 방식이 가장 쉬울 듯
    string name;
    int    n;

    cin >> name >> n;

    vector<int> name_check('Z' - 'A' + 1);
    for (const auto& c: name) {
        name_check[c - 'A']++;
    }
    LOG << name << "\n";

    vector<Winning_Name> list(n);
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;

        vector<int> temp_name_check(name_check.size());

        for (size_t i = 0; i < temp.size(); ++i) {
            temp_name_check[temp[i] - 'A']++;
        }

        int L = name_check['L' - 'A'] + temp_name_check['L' - 'A'];
        int O = name_check['O' - 'A'] + temp_name_check['O' - 'A'];
        int V = name_check['V' - 'A'] + temp_name_check['V' - 'A'];
        int E = name_check['E' - 'A'] + temp_name_check['E' - 'A'];

        long long score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
        list[i]         = { temp, score };
        LOG << list[i].name << " " << list[i].score << "\n";
    }

    q_sort(list, 0, list.size() - 1, [](const Winning_Name& a, const Winning_Name& b) {
        if (a.score == b.score) {
            return a.name < b.name;
        }

        return a.score > b.score;
    });

    cout << list.front().name;
}
