#include <stdio.h>

int main()
{
    char inputString;
    int numOfString;
    printf("Enter number of string: ");
    scanf("%d", &numOfString);
    const char* inputString = malloc(numOfString * sizeof(char));
}