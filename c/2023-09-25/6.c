// Įvesti iš klaviatūros simbolį ir išvesti į ekraną ar tai abėcėlės simbolis ar
// ne.

#include <stdio.h>

int main() {
    char a;

    scanf("%c", &a);

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        printf("part of the alphabet");
        return 0;
    }

    printf("not part of the alphabet :[");
    return 0;
}