#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    for (int i = 0; i <= x; i++) {
        for (int j = i; j < x; j++) {
            printf(" ");
        }

        for (int j = 0; j < i * 2; j++) {
            printf("*");
        }

        printf("\n");
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf(" ");
        }

        for (int j = 0; j < (x - i - 1) * 2; j++) {
            printf("*");
        }

        printf("\n");
    }
}
