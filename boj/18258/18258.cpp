#define LOCAL
//------------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>

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

vector<string> get_cmd(const string& s){
    if (s.empty()){
        return vector<string>();
    }

    vector<string> split;
    istringstream iss(s);
    string word;

    while(iss >> word){
        split.push_back(word);
    }

    return split;
}

void solution(){
    unordered_map<string, int> map;
    vector<string> cmd;
    cmd.push_back("push");
    cmd.push_back("pop");
    cmd.push_back("size");
    cmd.push_back("empty");
    cmd.push_back("front");
    cmd.push_back("back");

    for (int i = 0; i < cmd.size(); i++){
        map.insert(make_pair(cmd[i], i));
    } 

    string N;
    queue<string> q;

    getline(cin, N);

    int count = stoi(N);
    while (count--){

        string s;
        getline(cin,s);

        vector<string> input_cmd = get_cmd(s);

        unordered_map<string, int>::iterator it = map.find(input_cmd[0]);

        if (it != map.end()){
            switch(it->second){
                case 0 :{
                    q.push(input_cmd[1]);
                    break;
                }
                case 1  :{
                    if (q.empty()){
                        cout << -1;
                    } else {
                        cout << q.front();
                        q.pop();
                    }
                    end();
                    break;
                } 
                case 2  :{
                    cout << q.size();
                    end();
                    break;
                } 
                case 3  :{
                    q.empty() ? cout << 1 : cout << 0;
                    end();
                    break;
                }    
                case 4  :{
                    q.empty() ? cout << -1 : cout << q.front();
                    end();
                    break;
                }    
                case 5  :{
                    q.empty() ? cout << -1 : cout << q.back();
                    end();
                    break;
                }
            }
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