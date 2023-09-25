// Įvesti iš klaviatūros du sveikuosius skaičius ir išvesti į ekraną didžiausią.

#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    if (a > b) {
        printf("\n%d\n", a);
        return 0;
    }

    printf("%d\n", b);
    return 0;
}
