#define LOCAL
//------------------------------------------------------------------------------
#include <iostream>

using namespace std;

void end();
    
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
void solution(){
    int gov_count;

    cin >> gov_count;

    int budget[gov_count];
    int max = 0;

    for (int i = 0; i < gov_count; i++){
        cin >> budget[i];

        if (max < budget[i])
            max = budget[i];
    }

    int max_budget;

    cin >> max_budget;

    {
        int left = 0, right = max, middle, answer;

        while (left <= right){
            int sum = 0;
            middle = (left + right) / 2;

            for (int i = 0; i < gov_count; i++){
                sum += min(budget[i], middle);
            }

            if (sum > max_budget) {
                right = middle - 1;
            } else if(sum < max_budget){
                left = middle + 1;
                answer = middle;
            } else {
                answer = middle;
                break;
            }
        }

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
#else

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

        string my_answer = string(to_string(problem_number)+ "/my-answer-" + to_string(i) + ".txt");

        if (freopen(my_answer.c_str(), "w", stdout) == NULL){
            cout << "file open error" << endl;
            cerr << strerror(errno) << endl;
            return -1;
        }

        solution();
        cout << endl;
    }

    return 0;
}
#endif