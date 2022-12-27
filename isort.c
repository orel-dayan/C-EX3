#include <stdio.h>
#include <stdlib.h>
# define SIZE 50

void printArr(int *arr, int size)
{
    printf("%d", *arr);
    for (int i = 1; i < size; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
}

void shift_element(int* arr, int i)
{
   for(int j=0;j<i;j++)
   {
       *(arr+i-j)=*(arr+i-j-1);
   }
}
void insertion_sort(int* arr, int len) {
    int count;
   
    for (int i = 1; i < len; i++) {
        int *key = (arr + i-1);
         count = 0;
        while (*key>=*(arr+i))
        {
            count=count+1;
            key=key-1;
            
            if(key+1==arr)
            {
                break;
            }
        }
        key=key+1;
        int temp=*(arr+i);
        shift_element(key,count);
        *key=temp;      
    }
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printArr(arr, SIZE);
    return 0;
}
