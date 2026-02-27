#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string      str;
    stack<char> l, r;

    cin >> str;

    for (int b = 0; b < str.size(); b++) {
        l.push(str[b]);
    }

    int n;

    cin >> n;

    for (int a = 0; a < n; a++) {
        char j;

        cin >> j;

        if (j == 'P') {
            char k;

            cin >> k;
            l.push(k);
        } else if (j == 'B') {
            if (!l.empty()) {
                l.pop();
            }
        } else if (j == 'L') {
            if (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        } else if (j == 'R') {
            if (!r.empty()) {
                l.push(r.top());
                r.pop();
            }
        }
    }

    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }

    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }
}

