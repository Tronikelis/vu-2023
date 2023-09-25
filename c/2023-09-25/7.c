// Įvesti iš klaviatūros simbolį ir išvesti į ekraną ar tai balsė (a, e, y, i,
// u, o).

#include <stdio.h>

int main() {
    char a;

    scanf("%c", &a);

    switch (a) {
        case 97:
            printf("is a");
            return 0;
        case 101:
            printf("is e");
            return 0;
        case 121:
            printf("is y");
            return 0;
        case 105:
            printf("is i");
            return 0;
        case 117:
            printf("is u");
            return 0;
        case 111:
            printf("is o");
            return 0;
        default:
            printf("wtf you enter");
            return 1;
    }
}