// Įvesti iš klaviatūros sveikąjį skaičių N>0 (reikalingas patikrinimas) ir
// išvesti į ekraną skaičius nuo N iki 1. Papildomai atlikti tą patį tik
// išvedant į ekraną lyginius skaičius.

#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);

    if (a <= 0) {
        printf("int > 0");
        return 1;
    }

    int i = a;

    do {
        printf("%d\n", i);
        i--;
    } while (i > 0);
}