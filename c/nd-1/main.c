#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TRUE = 0;
int FALSE = 1;

int positive_count(int* arr, int length) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    return count;
}

int negative_count(int* arr, int length) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }

    return count++;
}

void fill_with_positives(int* from, int length, int* to) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (from[i] > 0) {
            to[count++] = from[i];
        }
    }
}

void fill_with_negatives(int* from, int length, int* to) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (from[i] < 0) {
            to[count++] = from[i];
        }
    }
}

int min(int a, int b) { return a < b ? a : b; }

int main() {
    srand(time(NULL));
    int target = 0;

    while (target <= 1) {
        printf("waiting for number > 1\n");
        int res = scanf("%d", &target);

        if (res != 1) {
            printf("that wasn't a number\n");
            int c;
            scanf("%c", &c);
        }
    }

    int* arr = malloc(target * sizeof(int));

    for (int i = 0; i < target; i++) {
        int payload = 0;
        // 0 💀
        while (payload == 0) {
            payload = (rand() % 100) - 100 / 2;
        }

        arr[i] = payload;
        printf("inserting: %8d\n", payload);
    }

    int positives = positive_count(arr, target);
    int negatives = negative_count(arr, target);

    if (positives == target || negatives == target) {
        printf("all random positives or negatives, exiting\n");
        return 0;
    }

    printf("\ncontinuing\n");

    int* only_positives = malloc(positives * sizeof(int));
    int* only_negatives = malloc(negatives * sizeof(int));

    fill_with_positives(arr, target, only_positives);
    fill_with_negatives(arr, target, only_negatives);

    printf("positives:\n");
    for (int i = 0; i < positives; i++) {
        printf("%8d\n", only_positives[i]);
    }

    printf("\nnegatives:\n");
    for (int i = 0; i < negatives; i++) {
        printf("%8d\n", only_negatives[i]);
    }

    printf(
        "\ncalculating with formula: S = +[i] * -[i] + (same thing i+1) N "
        "times, "
        "N = min(+,-)\n");

    int s = 0;
    for (int i = 0; i < min(positives, negatives); i++) {
        s += only_positives[i] * only_negatives[i];
    }

    printf("\nS = %4d\n", s);

    free(arr);
    free(only_positives);
    free(only_negatives);

    return 0;
}
