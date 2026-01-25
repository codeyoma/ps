#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int c;

    int a[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            c           = a[i][j];
            a[i][j]     = a[i][4 - j];
            a[i][4 - j] = c;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            c           = a[i][j];
            a[i][j]     = a[4 - i][j];
            a[4 - i][j] = c;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 2 || a[i][j] == 5) {
                printf("! ");
            } else {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
