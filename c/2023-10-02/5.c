// Įvesti iš klaviatūros mažąją raidę (reikalingas patikrinimas) ir išvesti į
// ekraną lotynišką abėcėlę pradedant įvesta raide.

#include <stdio.h>

int main() {
    char lowercase;

    scanf("%c", &lowercase);

    if (!(lowercase >= 97 && lowercase <= 122)) {
        printf("not lowercase");
        return 1;
    }

    int i = lowercase;

    do {
        printf("%c\n", i);
        i++;
    } while (i <= 122);
}