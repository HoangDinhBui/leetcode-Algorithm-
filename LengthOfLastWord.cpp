#include<stdio.h>
#include<string.h>
int lengthOfLastWord(const char* fullWord)
{
    int length = 0;
    int index = strlen(fullWord) - 1;
    while (index >= 0 && fullWord[index] == ' ')
    {
        index--;
    }
    while (index >= 0 && fullWord[index] == ' ')
    {
        length++;
        index--;
    }
    return length;
}
int main()
{
    char inputString[100];
    printf("Enter the string: ");
    fgets(inputString, sizeof(inputString), stdin);
    int result = lengthOfLastWord(inputString);
    printf("Length of last word is: ");
    printf("%d", result);
}