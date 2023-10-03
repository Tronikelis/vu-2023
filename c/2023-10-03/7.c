#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }
}