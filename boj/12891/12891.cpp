// https://www.acmicpc.net/problem/12891
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

#include <string>
#include <vector>

int main() {
    FAST_IO;

    //   logic
    int s, p;
    cin >> s >> p;

    vector<int> ans_t(128);
    vector<int> test_t(128);
    string      dna;
    string      set = "ACGT";
    cin >> dna;

    for (const auto c: set) {
        cin >> ans_t[c];
    }

    int answer = 0;

    for (int i = 0; i < p; ++i) {
        test_t[dna[i]] += 1;
    }

    auto is_matched = [&]() {
        bool unmatched = false;

        for (const auto c: set) {
            if (test_t[c] < ans_t[c]) {
                unmatched = true;
            }
        }

        if (!unmatched) {
            answer++;
        }
    };

    is_matched();

    for (int i = p; i < s; ++i) {
        test_t[dna[i - p]] -= 1;
        test_t[dna[i]] += 1;
        is_matched();
    }

    cout << answer;

    return 0;
}
