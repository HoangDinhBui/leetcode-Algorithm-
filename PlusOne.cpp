#include <iostream>

using namespace std;

void plusOne(int integer[], int numOfDigits)
{
    int intDigit = 0;
    for(int i = 0; i < numOfDigits; i++)
    {
        intDigit = intDigit * 10;
        intDigit = intDigit + integer[i];
    }
    intDigit += 1;
    for(int i = 0; i < numOfDigits; i++)
    {
        integer[i] = intDigit % 10;
        intDigit = intDigit / 10;
    }
}

void output(int integer[], int numOfDigits)
{
    cout << "Result: ";
    for(int i = numOfDigits - 1; i >= 0; i--)
        cout << integer[i] << " ";
}

void input(int integer[], int numOfDigits)
{
    for(int i = 0; i < numOfDigits; i++)
        cin >> integer[i];
}

int main()
{
    int numOfDigits;
    cout << "Enter number of digit: ";
    cin >> numOfDigits;
    int *integer = new int[numOfDigits];
    cout << "Enter the element of array: ";
    input(integer, numOfDigits);
    plusOne(integer, numOfDigits);
    output(integer, numOfDigits);
    delete[] integer;
    return 0;
}