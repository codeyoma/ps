#define LOCAL // need to delete in online judge
// https://www.acmicpc.net/problem/7569
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
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;

struct coor {
    int x;
    int y;
    int z;
    int day;
};

void solution()
{
    int m, n, h;
    int count = 0;

    cin >> m >> n >> h;

    VVV box(h, VV(n, V(m)));
    VVV visit(h, VV(n, V(m, 0)));
    queue<coor> q;

    for (int z = 0; z < h; ++z) {
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                int temp;
                cin >> temp;
                box[z][y][x] = temp;
                if (temp == 1) {
                    q.push({ x, y, z, 0 });
                    visit[z][y][x] = 1;
                } else if (temp == 0) {
                    ++count;
                }
            }
        }
    }

    int dx[] = { 0, 0, 0, 0, 1, -1 };
    int dy[] = { 0, 0, 1, -1, 0, 0 };
    int dz[] = { 1, -1, 0, 0, 0, 0 };

    int answer = -1;

    while (!q.empty()) {
        const auto [x, y, z, day] = q.front();
        q.pop();

        answer = day;

        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                continue;
            if (box[nz][ny][nx] != 0)
                continue;
            if (visit[nz][ny][nx] == 1)
                continue;

            visit[nz][ny][nx] = 1;
            q.push({ nx, ny, nz, day + 1 });
            --count;
        }
    }

    if (count != 0) {
        cout << -1;
    } else {
        cout << answer;
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
