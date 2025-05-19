#define LOCAL

#include <iostream>

void end();
    
using namespace std;

void solution(){
    bool student[30] = {0};

    for (int i = 0; i < 28; i++){
        int num;
        cin >> num;
        student[num - 1] = 1;
    }

    for (int i = 0; i < 30; i++){
        if (!student[i]){
            cout << i + 1;
            end();
        }
    }
}

void end(){
    #ifdef LOCAL
        cout << ' ';
    #else
        cout << endl;
    #endif
}

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