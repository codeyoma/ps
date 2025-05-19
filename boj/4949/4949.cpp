#define LOCAL
//------------------------------------------------------------------------------
#include <iostream>
#include <stack>

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
    while (true){
        string input;
        stack<char> s;
        int error = 0;

        getline(std::cin, input);

        if (input.size() == 1 && input.at(0) == '.') {
            break;
        }

        for(string::iterator it = input.begin(); it != input.end(); it++){
            switch (*it){
                case '(':
                case '[':
                    s.push(*it);
                    break;
                case ')':{
                    if (s.size() > 0 && s.top() == '('){
                        s.pop();
                    } else {
                        error = 1;
                    }
                    break;
                }
                case ']':{
                    if (s.size() > 0 && s.top() == '['){
                        s.pop();
                    } else {
                        error = 1;
                    }
                    break;
                }
            }
            
            if (error) break;
        }

        if (error || s.size() > 0){
            cout << "no";
        } else {
            cout << "yes";
        }
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
        cout << endl;
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