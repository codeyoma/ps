#define LOCAL // need to delete in online judge
// https://www.acmicpc.net/problem/14500
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

#include <vector>
using V = vector<bool>;
using VV = vector<V>;
using VVV = vector<VV>;

struct Block {
    VV shape;

    Block(VV s)
        : shape(s)
    {
    }

public:
    bool xy(const int& x, const int& y) const
    {
        return shape[y][x];
    }

    size_t width() const
    {
        if (!shape.empty()) {
            return shape[0].size();
        }
        return 0;
    }

    size_t height() const
    {
        return shape.size();
    }

    void print() const
    {
        for (size_t y = 0; y < height(); ++y) {
            for (size_t x = 0; x < width(); ++x) {
                if (shape[y][x])
                    cout << shape[y][x];
                else
                    cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void transform()
    {
        size_t n = height();
        size_t m = width();

        VV new_a(m, V(n));

        for (size_t y = 0; y < n; ++y) {
            for (size_t x = 0; x < m; ++x) {
                new_a[x][n - 1 - y] = xy(x, y);
            }
        }

        shape = new_a;
    }

    int transform_count()
    {
        if (height() == 1 && width() == 4)
            return 2;
        if (height() == 2 && width() == 2)
            return 1;
        return 4;
    }
};

void solution()
{
    std::vector<Block> tetris = {
        { { { 1, 1, 1, 1 } } }, // I-block (4×1)
        { { { 1, 1 },
            { 1, 1 } } }, // O-block (2×2)
        { { { 0, 0, 1 },
            { 1, 1, 1 } } }, // J-block
        { { { 1, 0, 0 },
            { 1, 1, 1 } } }, // L-block
        { { { 0, 1, 1 },
            { 1, 1, 0 } } }, // S-block
        { { { 1, 1, 0 },
            { 0, 1, 1 } } }, // Z-block
        { { { 1, 1, 1 },
            { 0, 1, 0 } } }, // T-block
    };

    size_t n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m));
    for (size_t y = 0; y < n; ++y) {
        for (size_t x = 0; x < m; ++x) {
            cin >> paper[y][x];
        }
    }

    int answer = C_MIN;

    for (auto& t : tetris) {
        for (int i = 0; i < t.transform_count(); ++i) {
            t.transform();
            // t.print();
            for (size_t y = 0; y < n; ++y) {
                for (size_t x = 0; x < m; ++x) {

                    // check boundary
                    if (((x + t.width()) > m) || ((y + t.height()) > n))
                        continue;

                    // sum
                    int sum = 0;
                    for (size_t iy = 0; iy < t.height(); ++iy) {
                        for (size_t ix = 0; ix < t.width(); ++ix) {
                            if (t.xy(ix, iy))
                                sum += paper[iy + y][ix + x];
                        }
                    }

                    // update max
                    answer = max(answer, sum);
                }
            }
        }
    }

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
