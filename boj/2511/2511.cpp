// https://www.acmicpc.net/problem/2511
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/2511/2511
#include <iostream>
#include <system_error>
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

#include <iostream>
#include <vector>

typedef enum class status {
    A,
    B,
    Draw
} Status;

int main() {
    fast_io();

    //   logic
    vector<int> a(10), b(10);

    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; ++i) {
        cin >> b[i];
    }

    Status s       = Status::Draw;
    int    a_score = 0;
    int    b_score = 0;

    for (int i = 0; i < 10; ++i) {
        if (a[i] > b[i]) {
            s = Status::A;
            a_score += 3;
        } else if (a[i] < b[i]) {
            s = Status::B;
            b_score += 3;
        } else {
            a_score++;
            b_score++;
        }
    }

    cout << a_score << " " << b_score << "\n";
    if (a_score > b_score) {
        cout << "A";
    } else if (a_score < b_score) {
        cout << "B";
    } else {
        switch (s) {
            case Status::A: {
                cout << 'A';
                break;
            }
            case Status::B: {
                cout << 'B';
                break;
            }
            case Status::Draw: {
                cout << 'D';
                break;
            }
        }
    }
}
