// Įvesti iš klaviatūros sveikąjį skaičių ir išvesti į ekraną ar jis yra lyginis
// ar ne.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a % 2 == 0) {
        printf("even");
        return 0;
    }

    printf("not even");
    return 0;
}