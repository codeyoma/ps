// https://www.acmicpc.net/problem/1543
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/1543/1543
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
#include <string>

int main() {
    //   logic
    string docu, word;
    int    count = 0;

    getline(cin, docu);
    getline(cin, word);

    for (size_t i = 0; i + word.size() <= docu.size(); ++i) {
        bool check = true;

        for (size_t j = 0; j < word.size(); ++j) {
            if (docu[i + j] != word[j]) {
                check = false;
                break;
            }
        }

        if (check) {
            count++;
            i += word.size() - 1;
        }
    }

    cout << count;
}
