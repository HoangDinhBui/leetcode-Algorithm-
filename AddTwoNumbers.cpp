#include <iostream>

using namespace std;

void addTwoNums(int listNode1[], int listNode2[], int numOfDigits)
{
    int *sumOfListNode = new int;
    for (int i = numOfDigits - 1; i >= 0; i--)
    {
        sumOfListNode[i] = listNode1[i] + listNode2[i];
    }
    for (int i = 0; i < numOfDigits; i++)
        cout << sumOfListNode[i] << ", ";
}

void input(int listNode[], int numOfDigits)
{
    for(int i = 0; i < numOfDigits; i++)
        cin >> listNode[i];
}
int main()
{
    int numOfDigits;
    cout << "Enter number of digits: ";
    cin >> numOfDigits;
    int *listNode1 = new int;
    int *listNode2 = new int;
    cout << "Enter the element of first number: ";
    input(listNode1, numOfDigits);
    cout << "Enter the element of second number: ";
    input(listNode2, numOfDigits);
    cout << "Result: ";
    addTwoNums(listNode1, listNode2, numOfDigits);
}