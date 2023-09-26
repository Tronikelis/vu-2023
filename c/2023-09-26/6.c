// Įvesti iš klaviatūros sveikąjį skaičių N>0 ir N<21 (reikalingas patikrinimas)
// ir išvesti į ekraną daugybos lentelę įvestam skaičiui. Daugybos operacijas
// atvaizduojame atskirose eilutėse.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);
    printf("\n");

    if (!(a > 0 && a < 21)) {
        printf("num should be between 0 and 21");
        return 1;
    }

    int i = 0;
    while (i < 9) {
        i++;
        printf("%d * %d = %d\n", a, i, a * i);
    }

    return 0;
}