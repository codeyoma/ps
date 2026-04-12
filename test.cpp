#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long int  lld;

lld CCW(pii P1, pii P2, pii P3) {
    return P1.first * (P2.second - P3.second) + P2.first * (P3.second - P1.second) + P3.first * (P1.second - P2.second);
}

int main() {
    vector<pii> P(4);

    for (int i = 0; i < 4; i++) {
        cin >> P[i].first >> P[i].second;
    }

    lld c1 = CCW(P[0], P[1], P[2]);
    lld c2 = CCW(P[0], P[1], P[3]);
    lld c3 = CCW(P[2], P[3], P[0]);
    lld c4 = CCW(P[2], P[3], P[1]);

    if ((c1 < 0 && c2 > 0)) {
        if (c3 > 0 && c4 < 0) {
            cout << 1;
        } else if (c3 < 0 && c4 > 0) {
            cout << 1;
        } else {
            cout << 0;
        }
    } else if (c1 > 0 && c2 < 0) {
        if (c3 > 0 && c4 < 0) {
            cout << 1;
        } else if (c3 < 0 && c4 > 0) {
            cout << 1;
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
}