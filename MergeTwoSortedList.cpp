#include <stdio.h>
//Function of sort merge Array
void sort(int mergeArr[], int numOfMergeArr)
{
    for(int i = 0; i < numOfMergeArr - 1; i++)
    {
        for(int j = i + 1; j < numOfMergeArr; j++)
        {
            if(mergeArr[i] > mergeArr[j])
            {
                int tmp = mergeArr[i];
                mergeArr[i] = mergeArr[j];
                mergeArr[j] = tmp;
            }
        }
    }
}
//Function of merge two array
void mergeArr(int sortedArr1[], int sortedArr2[], int numOfArr1, int numOfArr2)
{
    int index = 0;
    int numOfMergeArr = numOfArr1 + numOfArr2;
    int mergeArr[numOfMergeArr];
    // Copy elements from sortedArr1 to mergeArr
    for(int i = 0; i < numOfArr1; i++)
    {
        mergeArr[index] = sortedArr1[i];
        index++;
    }
    // Copy elements from sortedArr2 to mergeArr
    for(int i = 0; i < numOfArr2; i++)
    {
        mergeArr[index] = sortedArr2[i];
        index++;
    }
    //Sort merge array
    sort(mergeArr, numOfMergeArr);
    //Print sorted merge array
    printf("After merge: ");
    for(int i = 0; i < numOfMergeArr; i++)
    {
        printf("%d ", mergeArr[i]);
    }
}
int main()
{
    int numOfArr1, numOfArr2;
    //Setup 1st Array
    printf("Enter the number of 1st sorted array: ");
    scanf("%d", &numOfArr1);
    int sortedArr1[numOfArr1];
    printf("Enter the 1st array's element: ");
    for(int i = 0; i < numOfArr1; i++)
    {
        scanf("%d", &sortedArr1[i]);
    }
    //Setup 2nd Array
    printf("Enter the number of 2nd sorted array: ");
    scanf("%d", &numOfArr2);
    int sortedArr2[numOfArr2];
    printf("Enter the 2nd array's element: ");
    for(int i = 0; i < numOfArr2; i++)
    {
        scanf("%d", &sortedArr2[i]);
    }
    mergeArr(sortedArr1, sortedArr2, numOfArr1, numOfArr2);
}