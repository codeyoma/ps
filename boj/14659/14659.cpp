// https://www.acmicpc.net/problem/14659
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/14659/14659
//------------------------------------------------------------------------------
#define LOCAL // need to delete in online judge

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX (1234567891)
#define MIN (-1234567891)

#ifdef LOCAL
ostream _log(cout.rdbuf());
#else
struct nullstream : std::ostream {
    nullstream()
        : std::ostream(nullptr) {
    }
};
nullstream _log;
#endif

/**
 *------------------------------------------------------------------------------
 *                      /$$             /$$     /$$
 *                     | $$            | $$    |__/
 *   /$$$$$$$  /$$$$$$ | $$ /$$   /$$ /$$$$$$   /$$  /$$$$$$  /$$$$$$$
 *  /$$_____/ /$$__  $$| $$| $$  | $$|_  $$_/  | $$ /$$__  $$| $$__  $$
 * |  $$$$$$ | $$  \ $$| $$| $$  | $$  | $$    | $$| $$  \ $$| $$  \ $$
 *  \____  $$| $$  | $$| $$| $$  | $$  | $$ /$$| $$| $$  | $$| $$  | $$
 *  /$$$$$$$/|  $$$$$$/| $$|  $$$$$$/  |  $$$$/| $$|  $$$$$$/| $$  | $$
 * |_______/  \______/ |__/ \______/    \___/  |__/ \______/ |__/  |__/
 *------------------------------------------------------------------------------
 */

#include <vector>
void solution() {
    int n;
    cin >> n;
    vector<int> m(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    int max_a = MIN;

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (m[i] >= m[j]) {
                cnt++;
            } else {
                break;
            }
        }
        max_a = max(max_a, cnt);
    }
    cout << max_a;
}

/**
 *------------------------------------------------------------------------------
 *  /$$        /$$$$$$  /$$$$$$$$ /$$      /$$
 * | $$       /$$__  $$|__  $$__/| $$$    /$$$
 * | $$      | $$  \__/   | $$   | $$$$  /$$$$
 * | $$      | $$ /$$$$   | $$   | $$ $$/$$ $$
 * | $$      | $$|_  $$   | $$   | $$  $$$| $$
 * | $$      | $$  \ $$   | $$   | $$\  $ | $$
 * | $$$$$$$$|  $$$$$$/   | $$   | $$ \/  | $$
 * |________/ \______/    |__/   |__/     |__/
 *------------------------------------------------------------------------------
 */

#ifndef LOCAL // for online test
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    solution();
}

#else

#    include <fstream>
#    include <iomanip>
#    include <unistd.h>

class IORedirect {
    streambuf* orig_cin_buf;
    streambuf* orig_cout_buf;

public:
    IORedirect(istream& new_in, ostream& new_out) {
        orig_cin_buf  = cin.rdbuf(new_in.rdbuf());
        orig_cout_buf = cout.rdbuf(new_out.rdbuf());
    }

    ~IORedirect() {
        cin.rdbuf(orig_cin_buf);
        cout.rdbuf(orig_cout_buf);
    }
};

void _run_test(const int problem_number, const int test_number) {
    string test_input_file_name = to_string(problem_number) + "/test-input-" + to_string(test_number) + ".txt";
    string my_output_file_name  = to_string(problem_number) + "/my-output-" + to_string(test_number) + ".txt";

    ifstream test_input(test_input_file_name);
    ofstream my_output(my_output_file_name);

    IORedirect redirect(test_input, my_output);

    _log << setw(20) << right << setfill('-') << " test case - " + to_string(test_number) << " " << "------\n";

    solution();

    _log << "\n"
         << setw(27) << setfill('-') << ""
         << endl;
}

int main(int argc, char* argv[]) {
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    if (argc < 3 || argc > 4) {
        return -1;
    }

    int problem_number = stoi(argv[1]);
    int test_size      = stoi(argv[2]);
    int test_target    = (argc == 4) ? stoi(argv[3]) : 0;

    if (test_target == 0) {
        for (int i = 1; i <= test_size; i++) {
            _run_test(problem_number, i);
        }
    } else {
        _run_test(problem_number, test_target);
    }

    return 0;
}
#endif
