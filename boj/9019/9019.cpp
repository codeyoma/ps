#define LOCAL // need to delete in online judge
// https://www.acmicpc.net/problem/9019
//------------------------------------------------------------------------------
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T, typename... Args>
void log(const T& first, const Args&... rest);
void end();
// #define C_MIN (-(1e8 + 7))
// #define C_MAX (1e8 + 7)
#define C_MAX (1234567891)
#define C_MIN (-1234567891)
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

#include <queue>
#include <vector>

int dslr(const int& a, const char& cmd)
{
    int mod = 10'000;

    switch (cmd) {
    case 'D': {
        return (a * 2) % mod;
    }
    case 'S': {
        if (a == 0) {
            return 9999;
        }
        return a - 1;
    }
    case 'L': {
        int temp = (a * 10) % mod;
        int remain = a / 1000;
        return temp + remain;
    }
    case 'R': {
        int temp = (a / 10) % 1'000;
        int remain = a % 10;
        return remain * 1'000 + temp;
    }
    default: {
        return 0;
    }
    }
}

struct trail {
    int before;
    char how;
};

void solution()
{
    int t;
    cin >> t;
    string a_cmd = "DSLR";

    while (t--) {
        int a, b;
        cin >> a >> b;

        queue<int> q;
        vector<bool> visit(10000, false);
        vector<trail> path(10000);

        q.push(a);
        path[a] = { a, ' ' };
        visit[a] = true;

        while (!q.empty()) {
            const auto number = q.front();
            q.pop();

            if (number == b) {
                break;
            }

            for (size_t i = 0; i < a_cmd.length(); ++i) {
                int next_number = dslr(number, a_cmd[i]);
                if (visit[next_number])
                    continue;

                visit[next_number] = true;
                path[next_number] = { number, a_cmd[i] };
                q.push(next_number);
            }
        }

        trail t = path[b];
        string answer;

        while (t.how != ' ') {
            answer += t.how;
            t = path[t.before];
        }
        for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
            cout << *it;
        }
        cout << "\n";
    }
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
// for local test
void end()
{
#ifdef LOCAL
    cout << ' ';
#else
    cout << '\n';
#endif
}

#ifndef LOCAL
// for online test
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    solution();
}

template <typename T, typename... Args>
void log(const T& first, const Args&... rest)
{
}

#else

#include <unistd.h>

int redirect_to_tty()
{
    int original_stdout_fd = dup(fileno(stdout));

    fclose(stdout);

    if (freopen("/dev/tty", "w", stdout) == NULL) {
        cerr << "tty 장치 파일 열기 오류" << endl;
        return -1;
    }

    return original_stdout_fd;
}

void restore_stdout(int original_stdout_fd)
{
    dup2(original_stdout_fd, fileno(stdout));
}

void log_()
{
}

template <typename T, typename... Args>
void log_(const T& first, const Args&... rest)
{
    cout << first << " ";

    if (sizeof...(rest) > 0) {
        log_(rest...);
    } else {
        cout << "\n";
    }
}

template <typename T, typename... Args>
void log(const T& first, const Args&... rest)
{
    int original_stdout_fd = redirect_to_tty();

    if (original_stdout_fd != -1) {
        log_(first, rest...);
        restore_stdout(original_stdout_fd);
    }
}

// for local test
void _run_test(const int problem_number, const int test_number)
{
    string test = string(to_string(problem_number) + "/test-input-" + to_string(test_number) + ".txt");

    if (freopen(test.c_str(), "r", stdin) == NULL) {
        cout << "file open error" << endl;
        cerr << strerror(errno) << endl;
    }

    string my_answer = string(to_string(problem_number) + "/my-output-" + to_string(test_number) + ".txt");

    if (freopen(my_answer.c_str(), "w", stdout) == NULL) {
        cout << "file open error" << endl;
        cerr << strerror(errno) << endl;
    }

    log("test case - ", test_number);
    solution();
    cout << '\n';
}

int main(int argc, char* argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int problem_number = 0;
    int test_size = 0;
    int test_target = 0;

    if (argc == 3) {
        problem_number = stoi(argv[1]);
        test_size = stoi(argv[2]);
    } else if (argc == 4) {
        problem_number = stoi(argv[1]);
        test_size = stoi(argv[2]);
        test_target = stoi(argv[3]);
    } else {
        return -1;
    }

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
