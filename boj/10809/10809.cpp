#define LOCAL

#include <iostream>
#include <array>    

void end();
    
using namespace std;

void solution(){
    array<int, 26> checker;
    string S;

    checker.fill(-1);

    cin >> S;

    for (string::iterator it = S.begin(); it != S.end(); it++ ){
        if (checker[*it - 'a'] == -1){
            checker[*it - 'a'] = it - S.begin();
        }
    }

    for (auto number : checker){
        cout << number << ' ';
    }
}

void end(){
    #ifdef LOCAL
        cout << ' ';
    #else
        cout << endl;
    #endif
}

#ifndef LOCAL
int main(){
    solution();
}
#else
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