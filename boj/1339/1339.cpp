// https://www.acmicpc.net/problem/1339
#include <stdexcept>
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

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

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--

using namespace std;
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891; // prime
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL; // prime
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
int main() {
    FAST_IO;

    vector<int> table(26);

    int n, sum = 0;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        int bias = 1;

        for (int i = s.length() - 1; i >= 0; --i) {
            table[s[i] - 'A'] += bias;
            bias *= 10;
        }
    }

    sort(table.rbegin(), table.rend());

    int digit = 9;

    for (int i = 0; i < 26; ++i) {
        if (table[i] == 0) {
            break;
        }
        sum += table[i] * digit;
        digit--;
    }

    cout << sum;

    return 0;
}

/*
int main() {
    FAST_IO;

    //   logic
    // 알파벳 위치별 가중치
    // -> 정렬
    // 그리디하게 알파벳 숫자 배부
    // 숫자화 -> 누적  합

    vector<pair<int, char>> t(26);
    vector<int>             score(26);
    vector<string>          words;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.push_back(s);

        int bias = 1;

        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            int pos = *it - 'A';
            t[pos].first += bias;
            t[pos].second = pos;
            bias *= 10;
        }
    }

    sort(t.begin(), t.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    });

    for (int i = 0; i < 10; i++) {
        if (t[i].first == 0) {
            continue;
        }
        score[t[i].second] = 9 - i;
    }

    int answer = 0;

    for (const auto& word: words) {
        int temp = 0;

        for (int i = 0; i < word.length(); ++i) {
            temp *= 10;
            temp += score[word[i] - 'A'];
        }

        answer += temp;
    }

    cout << answer;

    return 0;
}
*/
