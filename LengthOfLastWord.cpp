#include<stdio.h>
#include<string.h>
//function of find the length of last word in a string
int lengthOfLastWord(const char* fullWord)
{
    int length = 0;
    int index = strlen(fullWord) - 1;
    while (index >= 0 && fullWord[index] == ' ')
    {
        index--;
    }
    while (index >= 0 && fullWord[index] != ' ')
    {
        length++;
        --index;
    }
    return length - 1;
}
//main function
int main()
{
    char inputString[100];
    printf("Enter the string: ");
    fgets(inputString, sizeof(inputString), stdin);
    int result = lengthOfLastWord(inputString);
    printf("Length of last word is: ");
    printf("%d", result);
}