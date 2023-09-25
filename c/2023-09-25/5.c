// Įvesti iš klaviatūros sveikąjį skaičių ir išvesti į ekraną ar jis dalinasi be
// liekanos iš 3.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a % 3 == 0) {
        printf("divisible by 3");
        return 0;
    }

    printf("not divisible by 3");
    return 0;
}