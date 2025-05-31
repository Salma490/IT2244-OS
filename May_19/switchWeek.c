 #include <stdio.h>
 int main() {
    int day;
    // Prompt user input
    printf("Enter the number between 1 to 7: ");
    scanf("%d", &day);
    // Determine the day of the week
    switch(day) {
        case 1:
            printf("Today is Sunday!\n");
            break;
        case 2:
            printf("Today is Monday!\n");
            break;
        case 3:
            printf("Today is Tuesday!\n");
            break;
        case 4:
            printf("Today is Wednesday!\n");
            break;
        case 5:
            printf("Today is Thursday!\n");
            break;
        case 6:
            printf("Today is Friday!\n");
            break;
        case 7:
            printf("Today is Saturday!\n");
            break;
        default:
            printf("Invalid input! Please enter a number between 1 and 7.\n");
    }
    return 0;
}