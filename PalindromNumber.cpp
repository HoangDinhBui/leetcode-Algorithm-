#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//9. Palidrom number
void splitNums(int digitsArr[], int checkedNum, int numOfDigits)
{
    for(int i = numOfDigits - 1; i >= 0; i--)
    {
        digitsArr[i] = checkedNum % 10;
        checkedNum = checkedNum / 10;
    }
}
void reverseArray(int inverseArr[], int numOfDigits)
{
    int start = 0;
    int end = numOfDigits - 1;
    
    while (start < end)
    {
        int temp = inverseArr[start];
        inverseArr[start] = inverseArr[end];
        inverseArr[end] = temp;
        start++;
        end--;
    }
}
bool checkPaliNum(int countTrue, int numOfDigits)
{
    return countTrue == numOfDigits;
}
int main()
{
    int numOfDigits, checkedNum, countTrue = 0;
    printf("Enter the numbers that need to check: ");
    scanf("%d", &checkedNum);
    if (checkedNum < 0)
    {
        printf("False!");
        return 0;
    }
    else
    {
        int tmp = checkedNum;
        numOfDigits = 0;
         while (tmp != 0)
        {
            tmp = tmp / 10;
            numOfDigits++;
        }
        int digitsArr[numOfDigits];
        splitNums(digitsArr, checkedNum, numOfDigits);
        int inverseArr[numOfDigits];
        for (int i = 0; i < numOfDigits; i++)
        {
            inverseArr[i] = digitsArr[i]; 
        }
        //inverse array
        reverseArray(inverseArr, numOfDigits);
        //check
        for (int i = 0; i < numOfDigits; i++)
        {
            if (inverseArr[i] == digitsArr[i])
            {
                countTrue++;
            }
        }
        checkPaliNum(countTrue, numOfDigits) ? printf("True!") : printf("False!");
    }
}