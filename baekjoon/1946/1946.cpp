#define LOCAL
#include <unistd.h>



//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

void end();
template <typename T, typename... Args>
void log(const T& first, const Args&... rest);
    
/**
 *------------------------------------------------------------------------------
                        /$$             /$$     /$$                    
 *                     | $$            | $$    |__/                    
 *   /$$$$$$$  /$$$$$$ | $$ /$$   /$$ /$$$$$$   /$$  /$$$$$$  /$$$$$$$ 
 *  /$$_____/ /$$__  $$| $$| $$  | $$|_  $$_/  | $$ /$$__  $$| $$__  $$
 * |  $$$$$$ | $$  \ $$| $$| $$  | $$  | $$    | $$| $$  \ $$| $$  \ $$
 *  \____  $$| $$  | $$| $$| $$  | $$  | $$ /$$| $$| $$  | $$| $$  | $$
 *  /$$$$$$$/|  $$$$$$/| $$|  $$$$$$/  |  $$$$/| $$|  $$$$$$/| $$  | $$
 * |_______/  \______/ |__/ \______/    \___/  |__/ \______/ |__/  |__/
 *------------------------------------------------------------------------------
 */

#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

void solution(){
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >>  N;

        vector<tuple<int, int> > list;
        for (int i = 0; i < N; i++){
            int a, b;

            cin >> a >> b;

            list.push_back(make_tuple(a, b));
        }

        sort(list.begin(), list.end(), [](const tuple<int, int>& a, const tuple<int, int>& b){
            return get<0>(a) < get<0>(b);
        });

        int top_rank = 1e8 + 7;
        int pick_count = 0;

        for (auto item: list){
            log(get<0>(item), get<1>(item));

            if (get<1>(item) < top_rank){
                pick_count++;
                top_rank = get<1>(item);
            }
        }

        log("\n");

        cout << pick_count;
        end();

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
void end(){
    #ifdef LOCAL
        cout << ' ';
    #else
        cout << '\n';
    #endif
}

#ifndef LOCAL
// for online test
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}

template <typename T, typename... Args>
void log(const T& first, const Args&... rest) {
}

#else

int redirect_to_tty() {
    int original_stdout_fd = dup(fileno(stdout));

    fclose(stdout);

    if (freopen("/dev/tty", "w", stdout) == NULL) {
        cerr << "tty 장치 파일 열기 오류" << endl;
        return -1;
    }

    return original_stdout_fd;
}

void restore_stdout(int original_stdout_fd) {
    dup2(original_stdout_fd, fileno(stdout));
}

template <typename T, typename... Args>
void log_(const T& first, const Args&... rest) {
    cout << first << " ";

    if constexpr (sizeof...(rest) > 0) {
        log_(rest...);
    } else {
        cout << "\n";
    }
}

template <typename T, typename... Args>
void log(const T& first, const Args&... rest) {
    int original_stdout_fd = redirect_to_tty();

    if (original_stdout_fd != -1){
        log_(first, rest...);
        restore_stdout(original_stdout_fd);
    }
}

// for local test
int main(int argc, char *argv[]){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int problem_number = 0;
    int test_size = 0;

    if (argc == 3){
        problem_number = stoi(argv[1]);
        test_size = stoi(argv[2]);
    } else {
        return -1;
    }

    for (int i = 1; i <= test_size; i++){
        string test = string(to_string(problem_number)+ "/test-input-" + to_string(i) + ".txt");

        if (freopen(test.c_str(), "r", stdin) == NULL){
            cout << "file open error" << endl;
            cerr << strerror(errno) << endl;
            return -1;
        }

        string my_answer = string(to_string(problem_number)+ "/my-output-" + to_string(i) + ".txt");

        if (freopen(my_answer.c_str(), "w", stdout) == NULL){
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