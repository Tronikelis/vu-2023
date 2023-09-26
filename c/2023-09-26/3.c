// Įvesti iš klaviatūros sveikąjį skaičių N>0 (reikalingas patikrinimas) ir
// išvesti į ekraną visų skaičių nuo 1 iki N kvadratus ir kubus. Vienoje
// eilutėje išvedame konkretų skaičių, jo kvadratą ir kubą.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a <= 0) {
        printf("int should be > 0");
        return 1;
    }

    int i = 0;
    while (i < a) {
        i++;
        printf("quad: %d, cube: %d\n", i * i, i * i * i);
    }

    return 0;
}