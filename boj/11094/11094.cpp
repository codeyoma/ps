// https://www.acmicpc.net/problem/11094
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/11094/11094
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <string>

int main() {
    fast_io();

    //   logic
    string simon = "Simon says";
    string t;
    getline(cin, t);
    int n = stoi(t);

    while (n--) {
        string temp;
        getline(cin, temp);

        LOG << temp << "\n";
        string::size_type pos = temp.find(simon);

        if (pos != string::npos) {
            cout << temp.substr(simon.size()) << "\n";
        }
    }
}
