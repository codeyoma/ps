// https://www.acmicpc.net/problem/10826
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

// typedef long long ll;
using ll = long long;

constexpr int _MAX  = 1'234'567'891;
constexpr int _MIN  = -_MAX;
constexpr ll  __MAX = 1'111'111'111'111'111'111LL;
constexpr ll  __MIN = -__MAX;

//--------------------------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <string>

string add(const string& a, const string& b) {
    string result;

    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }

        if (j >= 0) {
            sum += b[j--] - '0';
        }

        result.push_back(char((sum % 10) + '0'));
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    FAST_IO

    //   logic
    int n;
    cin >> n;

    string a = "0", b = "1";

    if (n == 0) {
        cout << a;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        string c = add(a, b);
        a        = b;
        b        = c;
    }
    cout << a;
}
