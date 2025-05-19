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

#include <vector>
#include <queue>
void solution(){
    size_t v, e, start;

    cin >> v >> e >> start;
    start--;

    vector<vector<pair<int, int> > >    graph(v, vector<pair<int, int> >(0));
    vector<int>                         dist(v);

    fill(dist.begin(), dist.end(), C_MAX);

    {
        for (size_t i = 0; i < e; i++){
            int u, v , w;

            cin >> u >> v >> w;

            graph[u - 1].push_back(make_pair(v - 1, w));
        }
    }

    {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        dist[start] = 0;

        pq.push(make_pair(dist[start], start ));

        while (!pq.empty()) {
            pair<int, int> temp = pq.top();
            pq.pop();

            if (temp.first != dist[temp.second])
                continue;

            for (const auto& it: graph[temp.second]){
                log(temp.second, '-', it.first);
                log(dist[it.first], dist[temp.second], it.second);

                if (dist[it.first] > dist[temp.second] + it.second){
                    dist[it.first] = dist[temp.second] + it.second;
                    pq.push(make_pair(dist[it.first], it.first));
                }
            }
        }

        for (size_t i = 0; i < v; i++){
            if (dist[i] == C_MAX){
                cout << "INF";
            } else {
                cout << dist[i];
            }
            end();
        }
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

#include <unistd.h>

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

void log_(){

}

template <typename T, typename... Args>
void log_(const T& first, const Args&... rest) {
    cout << first << " ";

    if (sizeof...(rest) > 0) {
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