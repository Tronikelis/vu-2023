#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    int count = 0;

    for (int i = 0; i < x; i++) {
        for (int j = i; j < x - 1; j++) {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++) {
            count++;
            printf("%d ", count);
        }

        printf("\n");
    }
}