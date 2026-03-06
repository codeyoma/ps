#include <algorithm>
#include <iostream>

using namespace std;

int n1[500001];

int leftBound(int target, int n) {
    int low    = 0;
    int high   = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2; // low + (high - low) / 2 가 더 안전, low + high 연산이 오버플로우 일어나면 의도치 않은 값이 됨

        if (n1[mid] < target) {
            low = mid + 1;
        } else { // 같으면 내려가 보기
            high = mid - 1;
        }

        if (n1[mid] == target) {
            result = mid;
        }
    }

    return result;
}

int rightBound(int target, int n) {
    int low    = 0;
    int high   = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (n1[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> n1[i];
    }

    sort(n1, n1 + n);

    cin >> m;

    for (int j = 0; j < m; j++) {
        int x;
        cin >> x;

        int l = leftBound(x, n);
        int r = rightBound(x, n);

        if (l == -1) {
            cout << 0 << " ";
        } else {
            cout << (r - l) << " ";
        }
    }

    return 0;
} // 시간초과나는 이유를 모르겠어요