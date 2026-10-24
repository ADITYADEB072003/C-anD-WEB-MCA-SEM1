#include <stdio.h>
int main(){
    int arr[5];
    int *ptr=arr;
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("Enter %d elements of array\n",length);
    for(int i=0;i<length;i++){
        scanf("%d",(ptr+i));
    }
    printf("The elements of array are:\n");
    for(int i=0;i<length;i++){
        printf("%d \n",*(ptr+i));
    }
    printf("The elements of array using pointer arithmetic are:\n");
    ptr=arr;
    for(int i=0;i<length;i++){
        printf("%d \n",*ptr++);
    }
    int sum=0;
    ptr=arr;
    for(int i=0;i<length;i++){
        sum+=*ptr++;
    }
    printf("The sum of the elements of array is: %d\n",sum);
    return 0;
}