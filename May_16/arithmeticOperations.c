#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Addition: %d\n", num1 + num2);
    printf("Subtraction: %d\n", num1 - num2);
    printf("Multiplication: %d\n", num1 * num2);
    printf("Division: %.2f\n", (float)num1 / num2);  // cast to float for accurate division
    printf("Modulus: %d\n", num1 % num2);

    return 0;
}
