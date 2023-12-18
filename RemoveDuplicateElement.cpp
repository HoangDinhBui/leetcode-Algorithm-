#include <stdio.h>
int main()
{
    int numOfElement;
    printf("Enter the number of element of sorted array: ");
    scanf("%d", &numOfElement);
    int sortedArr[numOfElement];
    printf("Enter the element of sorted array: ");
    for(int i = 0; i < numOfElement; i++)
    {
        scanf("%d", &sortedArr[i]);
    }
    // Remove duplicates by replacing them with -1
    for(int i = 0; i < numOfElement - 1; i++)
    {
        for(int j = i + 1; j < numOfElement; j++)
        {
            if(sortedArr[i] == sortedArr[j])
            {
                sortedArr[j] = -1;
            }
        }
    }
    // Print the modified array without duplicates
    for(int i = 0; i < numOfElement; i++)
    {
        if(sortedArr[i] != -1)
            printf("%d ", sortedArr[i]);
    }
    return 0;
}