// https://www.acmicpc.net/problem/14713
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/14713/14713
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
#include <queue>
#include <string>
#include <vector>

int main() {
    //   logic
    int n;
    cin >> n;
    cin.ignore();

    vector<queue<string>> v(n);
    vector<string>        target_v;

    for (int i = 0; i < n; ++i) {
        string::size_type pos = 0;
        string            line;
        getline(cin, line);

        while ((pos = line.find(' ', pos)) != string::npos) {
            v[i].push(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos  = 0;
        }
        if (!line.empty()) {
            v[i].push(line);
        }
    }

    {
        string::size_type pos = 0;
        string            target;
        getline(cin, target);

        while ((pos = target.find(' ', pos)) != string::npos) {
            target_v.push_back(target.substr(0, pos));
            target = target.substr(pos + 1);
            pos    = 0;
        }
        if (!target.empty()) {
            target_v.push_back(target);
        }
    }

    for (size_t i = 0; i < target_v.size(); ++i) {
        bool found = false;

        for (size_t j = 0; j < v.size(); ++j) {
            if (v[j].empty()) {
                continue;
            }
            if (target_v[i] == v[j].front()) {
                LOG << target_v[i] << "  " << v[j].front() << "\n";
                v[j].pop();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!v[i].empty()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    cout << "Possible\n";
}
