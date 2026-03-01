// https://www.acmicpc.net/problem/32069
#if defined(__GNUC__) && defined(__x86_64__)
#    pragma GCC optimize("O3")
#    pragma GCC optimize("Ofast")
#    pragma GCC optimize("unroll-loops")
#    pragma GCC target("avx,avx2,fma")
#endif

#include <iostream>
using namespace std;
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using ll = long long;

ll  tele[300'001];
int bri[500'001];
int q, k;

void push(ll x) {
    if (k < x) {
        x = k;
    }

    if (x) {
        bri[x]++;
        q++;
    }
}

int main() {
    FAST_IO;
    ll  l;
    int n;
    cin >> l >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tele[i];
    }
    for (int i = 0; i < n && k; ++i) {
        cout << "0\n";
        k--;
    }
    push(tele[0]);
    push(l - tele[n - 1]);
    for (int i = 0; i < n - 1; ++i) {
        ll dist = tele[i + 1] - tele[i];
        push(dist / 2);
        push((dist - 1) / 2);
    }
    int i = 1;
    while (k) {
        for (int t = q; k && t; k--, t--) {
            cout << i << "\n";
        }
        q -= bri[i++];
    }
    return 0;
}