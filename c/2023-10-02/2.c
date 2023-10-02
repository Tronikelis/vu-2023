// Naudojantis ciklo sakiniu įvesti iš klaviatūros N sveikų skaičių. Ciklas turi
// sustoti įvedus iš klaviatūros nulį. Susumuoti įvestus skaičius ir išvesti jų
// sumą į ekraną. Papildomai atlikti tą patį tik sumuojant nelyginius skaičius.

#include <stdio.h>

int main() {
    int sum = 0;

    int current;

    do {
        scanf("%d", &current);
        sum += current;
    } while (current > 0);

    printf("%d\n", sum);
}