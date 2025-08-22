// https://www.acmicpc.net/problem/1159
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1159/1159
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

typedef struct name {
    char c;
    int  count;
} Name;

int main() {
    //   logic
    int n;
    cin >> n;

    vector<Name> list('z' - 'a' + 1);

    bool is_there_any = false;

    while (n--) {
        string input;
        cin >> input;

        list[input.front() - 'a'] = { input.front(), list[input.front() - 'a'].count + 1 };
        if (list[input.front() - 'a'].count >= 5) {
            is_there_any = true;
        }
    }

    if (is_there_any == false) {
        cout << "PREDAJA";
    } else {
        for (const auto& i: list) {
            if (i.count >= 5) {
                cout << i.c;
            }
        }
    }
}
