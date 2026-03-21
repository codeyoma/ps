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

    vector<int> name_check(256);
    for (const auto& c: name) {
        name_check[c]++;
    }

    vector<Winning_Name> list(n);
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;

        vector<int> temp_name_check(name_check.size());

        for (size_t i = 0; i < temp.size(); ++i) {
            temp_name_check[temp[i]]++;
        }

        int L = name_check['L'] + temp_name_check['L'];
        int O = name_check['O'] + temp_name_check['O'];
        int V = name_check['V'] + temp_name_check['V'];
        int E = name_check['E'] + temp_name_check['E'];

        long long score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
        list[i]         = { temp, score };
    }

    sort(list.begin(), list.end(), [](const Winning_Name& a, const Winning_Name& b) {
        if (a.score == b.score) {
            return a.name < b.name;
        }

        return a.score > b.score;
    });

    cout << list.front().name;
}
