// boj.kr/10818
// boj.kr/2675

#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  scanf("%d", &n);

  while (n--) { // (2, 1) - true | 0-> false
    int size;
    char *string = NULL; // (0x0)

    scanf("%d", &size); // size 변수의 주소에다가 넣어라
    string = (char *)calloc(sizeof(char) * (20 + 1), 0);
    scanf("%s", string); // memory 21 칸에다가 처음 위치부터 값을 넣어 준다

    int i = 0;
    // 3 abc
    // aaabbbccc
    while (string[i] != '\0') {        // 한 글자 뽑기
      for (int j = 0; j < size; ++j) { // 글자들 반복
        printf("%c", string[i]);
      }
      i++;
    }
    printf("\n");
    free(string);
  }
}
