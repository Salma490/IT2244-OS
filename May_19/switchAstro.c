 #include <stdio.h>
 int main() {
    int date, a, b, c;
    // Get date of birth from user
    printf("Enter your birth date (1-31): ");
    scanf("%d", &date);
    // Check for valid date
    if(date < 1 || date > 31) {
        printf("Invalid date! Please enter a date between 1 and 31.\n");
        return 1;
    }
    // Calculate life path number
    a = date % 10;      // Units digit
    b = date / 10;      // Tens digit
    c = a + b;          // Life path number
    // If sum is greater than 9, reduce to single digit
    if (c > 9) {
        c= (c % 10) + (c / 10);
    }
 
 // Display calculated values
    printf("Calculation for life path number:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("Life path number = %d\n", c);
    // Switch case for life path meanings
    switch(c) {
        case 1:
            printf("You are Lucky!\n");
            break;
        case 2:
            printf("Carefully do your work.\n");
            break;
        case 3:
            printf("You are Stronger.\n");
            break;
        case 4:
            printf("You are Happy.\n");
            break;
        case 5:
            printf("You can get help.\n");
            break;
        case 6:
            printf("You have Doubt.\n");
            break;
        case 7:
            printf("You are Sad.\n");
            break;
        case 8:
            printf("You Like things.\n");
            break;
        case 9:
            printf("You have Courage.\n");
            break;
        default:
            printf("Invalid life path number.\n");
    }
    return 0;
 }