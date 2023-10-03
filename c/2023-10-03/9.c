#include <stdio.h>

int main() {
    int x;

    scanf("%d", &x);

    int count = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = i; j < x; j++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            count++;
            printf("%d ", count);
        }

        printf("\n");
    }
}