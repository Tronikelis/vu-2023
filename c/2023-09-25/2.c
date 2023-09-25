// Įvesti iš klaviatūros tris sveikuosius skaičius ir išvesti į ekraną mažiausią
// iš jų.

#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int smallest = a;

    if (smallest > b) {
        smallest = b;
    }

    if (smallest > c) {
        smallest = c;
    }

    printf("smallest: %d", smallest);
}