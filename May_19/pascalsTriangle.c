#include <stdio.h>

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int i, j, space;
    for (i = 0; i < rows; i++) {
        for (space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }

        long long value = 1;

        for (j = 0; j <= i; j++) {
            printf("%4lld", value);
            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}
