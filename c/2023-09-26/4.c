// Įvesti iš klaviatūros sveikąjį skaičių N>0 (reikalingas patikrinimas) ir
// išvesti į ekraną kas trečią skaičių pradedant nuo -N iki N.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);
    printf("\n");

    if (a <= 0) {
        printf("int should be > 0");
        return 1;
    }

    int i = -a;
    int count = 0;

    while (i < a) {
        count++;
        if (count % 3 == 0) {
            printf("%d\n", i);
        }

        i++;
    }

    return 0;
}