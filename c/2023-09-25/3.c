// Įvesti iš klaviatūros sveikąjį skaičių ir išvesti į ekraną ar jis yra
// neigiamas, teigiamas ar lygus nuliui.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a > 0) {
        printf("positive");
        return 0;
    }

    if (a < 0) {
        printf("negative");
        return 0;
    }

    printf("is 0");
    return 0;
}