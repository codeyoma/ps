// https://www.acmicpc.net/problem/22341
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

#include <iostream>
#include <vector>

struct coor {
    int x;
    int y;
};

int main() {
    int n, c;
    cin >> n >> c;

    vector<coor> dots(n);

    for (int i = 0; i < c; ++i) {
        coor temp;
        cin >> temp.x >> temp.y;
        dots[i] = temp;
    }

    //---

    int r_m = n, c_m = n;

    for (int i = 0; i < c; ++i) {
        LOG << dots[i].x << " " << dots[i].y << endl;
        if (dots[i].x >= r_m || dots[i].y >= c_m) {
            continue;
        }
        int row_cut = dots[i].x * c_m;
        int col_cut = dots[i].y * r_m;

        if (row_cut < col_cut) {
            c_m = dots[i].y;
        } else {
            r_m = dots[i].x;
        }
    }
    cout << r_m * c_m;
}
