 #include <stdio.h>
 int main() {
    int n, i, num;
    int sum = 0;
    int product = 1;
    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        sum += num;         
        product *= num;     
    }
    printf("Summation = %d\n", sum);
    printf("Multiplication = %d\n", product);
    return 0;
 }