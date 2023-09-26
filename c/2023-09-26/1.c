// Įvesti iš klaviatūros sveikąjį skaičių N>0 (reikalingas patikrinimas) ir
// išvesti į ekraną skaičius nuo 1 iki N. Papildomai atlikti tą patį tik
// išvedant į ekraną nelyginius skaičius.

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
        printf("%d\n", i);
    }

    return 0;
}