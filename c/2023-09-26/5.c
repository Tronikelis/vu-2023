// Įvesti iš klaviatūros mažąją raidę (reikalingas patikrinimas) ir išvesti į
// ekraną lotynišką abėcėlę pradedant įvesta raide. Sudėtingesnis variantas:
// išvesti abėcėlę mažosioms ar didžiosioms raidėms priklausomai nuo to ką įvedė
// vartotojas.

#include <stdio.h>

int main() {
    char a;

    int ALPHA_z = 122;
    int ALPHA_a = 97;

    int ALPHA_A = 65;
    int ALPHA_Z = 90;

    scanf("%c", &a);
    printf("\n");

    if (!((a >= ALPHA_a && a <= ALPHA_z) || (a >= ALPHA_A && a <= ALPHA_Z))) {
        printf("enter a alphabet character");
        return 1;
    }

    int is_lower = a >= ALPHA_a && a <= ALPHA_z ? 1 : 0;

    if (is_lower) {
        int i = a;
        while (i <= ALPHA_z) {
            printf("%c\n", i);
            i++;
        }

        return 0;
    }

    int i = a;
    while (i <= ALPHA_Z) {
        printf("%c\n", i);
        i++;
    }

    return 0;
}