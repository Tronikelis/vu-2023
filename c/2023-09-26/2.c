// Įvesti iš klaviatūros sveikąjį skaičių N>0 (reikalingas patikrinimas) ir
// išvesti į ekraną skaičių sumą nuo 1 iki N. Papildomai atlikti tą patį tik
// sumuojant kas antrą skaičių.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a <= 0) {
        printf("int should be > 0");
        return 1;
    }

    int sum = 0;
    int i = 0;

    while (i < a) {
        i++;
        sum += i;
    }

    printf("sum: %d\n", sum);
    return 0;
}