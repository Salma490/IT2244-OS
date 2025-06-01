#include <stdio.h>

int main(){
    int n, i;
    int max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if(n<=0){
        printf("Array size should be positive.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n);

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i=1; i<n; i++){
        if(arr[i]>max){
            max=arr[i];
        }

        if(arr[i]<min){
            min=arr[i];
        }
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}