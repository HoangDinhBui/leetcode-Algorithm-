#include <stdio.h>
int main()
{
    //declare array and size of array
    int arr[100], numOfElement;
    //input size array
    printf("Enter the number of array's elements: ");
    scanf("%d", &numOfElement);
    //input array with size just import
    printf("Enter the elements of array: ");
    for(int i = 0; i < numOfElement; i++)
    {
        scanf("%d", &arr[i]);
    }
    //declare target variable
    int target;
    //input targer number
    printf("Enter the number you needed to remove: ");
    scanf("%d", &target);
    //remove element equal to target
    for(int i = 0; i < numOfElement; i++)
    {
        if(arr[i] == target)
        {
            arr[i] = -1;
        }
    }
    //print array after remove
    for(int i = 0; i < numOfElement; i++)
    {
        if(arr[i] != -1)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}