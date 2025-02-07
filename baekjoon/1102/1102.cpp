#include <cstddef>
#define LOCAL // need to delete in online judge
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;
template <typename T, typename... Args>
void log(const T& first, const Args&... rest);
void end();
#define C_MIN (-(1e8 + 7))
#define C_MAX (1e8 + 7)
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
#include <cmath>
#include <vector>

int dp(int mask, vector<vector<int>>& cost, vector<int>& cache, const int& n, const int& p)
{
    int ret = C_MAX, count = 0;

    if (cache[mask] != -1)
        return cache[mask];

    for (int i = 0; i < n; i++) {
        if (mask & int(pow(2, i)))
            count++;
    }

    if (count >= p) {
        cache[mask] = 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (mask & int(pow(2, i))) {

            for (int j = 0; j < n; j++) {
                if (!(mask & int(pow(2, j)))) {
                    ret = min(ret, cost[i][j] + dp(mask + int(pow(2, j)), cost, cache, n, p));
                }
            }
        }
    }

    cache[mask] = ret;

    return ret;
}

void solution()
{
    int n, p;
    string s;

    cin >> n;

    vector<vector<int>> cost(n, vector<int>());

    vector<int> cache(floor(pow(2, n)), -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;

            cin >> temp;
            cost[i].push_back(temp);
        }
    }

    cin >> s >> p;

    int init_mask = 0;

    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == 'Y')
            init_mask += floor(pow(2, i));
    }

    log("", init_mask);

    int answer = dp(init_mask, cost, cache, n, p);

    if (answer == C_MAX)
        cout << -1;
    else
        cout << answer;
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
    cin.tie(NULL);
    cout.tie(NULL);
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
int main(int argc, char* argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int problem_number = 0;
    int test_size = 0;

    if (argc == 3) {
        problem_number = stoi(argv[1]);
        test_size = stoi(argv[2]);
    } else {
        return -1;
    }

    for (int i = 1; i <= test_size; i++) {
        string test = string(to_string(problem_number) + "/test-input-" + to_string(i) + ".txt");

        if (freopen(test.c_str(), "r", stdin) == NULL) {
            cout << "file open error" << endl;
            cerr << strerror(errno) << endl;
            return -1;
        }

        string my_answer = string(to_string(problem_number) + "/my-output-" + to_string(i) + ".txt");

        if (freopen(my_answer.c_str(), "w", stdout) == NULL) {
            cout << "file open error" << endl;
            cerr << strerror(errno) << endl;
            return -1;
        }

        log("test case - ", i);
        solution();
        cout << '\n';
    }

    return 0;
}
#endif