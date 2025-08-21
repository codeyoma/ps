// https://www.acmicpc.net/problem/23056
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
#include <unordered_map>
#include <vector>

typedef struct candi {
    int    class_number;
    string name;
} Candi;

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

int main() {
    //   logic

    int n, m;
    cin >> n >> m;

    vector<Candi>           list;
    unordered_map<int, int> dup_check;

    while (true) {
        int    class_number;
        string name;

        cin >> class_number >> name;

        if (class_number == 0 && name == "0") {
            break;
        }
        if (dup_check.count(class_number) && dup_check.at(class_number) >= m) {
            continue;
        }
        dup_check[class_number]++;
        list.push_back({ class_number, name });
    }

    q_sort(list, 0, list.size() - 1, [](const Candi& a, const Candi& b) {
        bool odd_a = a.class_number & 1;
        bool odd_b = b.class_number & 1;

        if (odd_a != odd_b) {
            return odd_a;
        }

        if (a.class_number != b.class_number) {
            return a.class_number < b.class_number;
        }

        if (a.name.length() != b.name.length()) {
            return a.name.length() < b.name.length();
        }
        return a.name < b.name;
    });

    for (const auto& i: list) {
        cout << i.class_number << " " << i.name << "\n";
    }
}
