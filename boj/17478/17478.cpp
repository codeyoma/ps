// https://www.acmicpc.net/problem/17478
// https://codeyoma.github.io/Computer-Science/1-Foundations--and--Theory/Algorithms/ps/boj/17478/17478
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

string make_dash(int n) {
    string dash;

    for (int i = 0; i < n; ++i) {
        dash.append("____");
    }

    return dash;
}

void jh(int start, int target) {
    string dash = make_dash(start);

    cout << dash << "\"재귀함수가 뭔가요?\"\n";

    if (start >= target) {
        cout << dash << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout << dash << "라고 답변하였지.\n";
        return;
    }

    cout << dash << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout << dash << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout << dash << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

    jh(start + 1, target);

    cout << dash << "라고 답변하였지.\n";
}

void solution() {
    int n;

    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    jh(0, n);
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
