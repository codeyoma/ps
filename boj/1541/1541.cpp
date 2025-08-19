// https://www.acmicpc.net/problem/1541
#include <iostream>
using namespace std;

#ifdef LOCAL
#    define LOG clog
#else
struct nullstream : ostream {
    nullstream()
        : ostream(nullptr) {}
};
nullstream LOG;
#endif

//--------------------------------------------------------------------------------------------------

#define MAX (1234567891)
#define MIN (-1234567891)

#include <iostream>
#include <string>
#include <vector>

int main() {
    //   logic
    // + 면 벡터 뒤의 숫자에 더하기
    // - 면 벡터 맨뒤에 요소 추가
    // 일괄적으로 - 연산

    string expression;
    cin >> expression;

    vector<int> temp_expression;
    size_t      i         = 0;
    bool        plus_sign = false;

    while (i < expression.size()) {
        if (expression[i] == '-' || expression[i] == '+') {
            int number = stoi(expression.substr(0, i));

            if (!plus_sign) {
                temp_expression.push_back(number);
            } else {
                temp_expression[temp_expression.size() - 1] += number;
            }

            if (expression[i] == '-') {
                plus_sign = false;
            } else {
                plus_sign = true;
            }

            expression = expression.substr(i + 1);
            i          = 0;
        } else {
            i++;
        }
    }

    if (!plus_sign) {
        temp_expression.push_back(stoi(expression));
    } else {
        temp_expression[temp_expression.size() - 1] += stoi(expression);
    }

    int answer = temp_expression[0];
    for (size_t i = 1; i < temp_expression.size(); ++i) {
        answer -= temp_expression[i];
    }

    cout << answer;
}

// - 이후론 다 - 처리하는 로직
// int main() {
//     string expr;
//     cin >> expr;

//     int result = 0;
//     int num = 0;
//     bool minus_mode = false;

//     for (size_t i = 0; i <= expr.size(); i++) {
//         if (i == expr.size() || expr[i] == '+' || expr[i] == '-') {
//             if (minus_mode) result -= num;
//             else result += num;
//             num = 0;

//             if (i < expr.size() && expr[i] == '-') {
//                 minus_mode = true; // 이후부터는 전부 빼기
//             }
//         } else {
//             num = num * 10 + (expr[i] - '0'); // 숫자 누적
//         }
//     }

//     cout << result;
// }

#include <deque>
void _deque_solution() {
    string in;
    bool   next_is_plus = false;
    cin >> in;

    deque<int> dq;

    size_t i = 0;

    while (i < in.length()) {
        if (in[i] == '-' || in[i] == '+') {
            int number = stoi(in.substr(0, i));

            if (!dq.empty() && next_is_plus) {
                number += dq.back();
                dq.pop_back();
            }

            dq.push_back(number);

            if (in[i] == '+') {
                next_is_plus = true;
            } else {
                next_is_plus = false;
            }
            in = in.substr(i + 1);
            i  = 0;

        } else {
            ++i;
        }
    }

    int number = stoi(in);

    if (next_is_plus) {
        number += dq.back();
        dq.pop_back();
    }

    dq.push_back(number);
    number = dq.front();
    dq.pop_front();
    for (auto& i: dq) {
        number -= i;
    }
    cout << number;
}
