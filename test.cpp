#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string        str[n];
    string        writing;
    queue<string> q[n];
    queue<string> write;

    for (int i = 0; i < n; i++) {
        getline(cin, str[i]);
        string tmp = "";

        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] == ' ') {
                q[i].push(tmp);
                tmp = "";
            } else {
                tmp += str[i][j];
            }
        }

        if (tmp != "") {
            q[i].push(tmp);
            tmp = "";
        }
    }

    getline(cin, writing);
    string ttmp = "";
    for (int i = 0; i < writing.length(); i++) {
        if (writing[i] == ' ') {
            write.push(ttmp);
            ttmp = "";
        } else {
            ttmp += writing[i];
        }
    }

    if (ttmp != "") {
        write.push(ttmp);
        ttmp = "";
    }

    int ss = write.size();
    for (int i = 0; i < ss; i++) { // 큐의 사이즈 만큼 도는 조건이지만, 큐가 pop()되면 사이이즈가 줄어듬 // while이나 고정 n = write.size(); 로 저장해서 사용하기
        for (int j = 0; j < n; j++) {
            if (!write.empty() && write.front() == q[j].front()) {
                q[j].pop();
                write.pop();
            }
        }
    }

    if (write.empty()) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }

    return 0;
}
