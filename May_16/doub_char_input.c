#include <stdio.h>

int main(){
    //	int firstNum, secondNum=25;
	int firstNum=25;
	printf("fist number: %d\n",firstNum);
	int secondNum=firstNum;
	printf("second number: %d\n",secondNum);
	return 0;

    float num1=10.9f; //using of we indicatet the
    printf("%f \n", num1);//output 10.0000000
    printf("%.1f \n", num1);//output 10.9

    char character='z';
	printf("%c \n",character);
	printf("%d \n",character);


    double number;
    char alpha;
    printf("Enter double input : ");
    scanf("%lf", &number);
    printf("Your number is : %lf\n", number);

    printf("Enter character : ");
    scanf(" %c", &alpha);
    printf("Your character :%c \n", alpha);

    return 0;
}