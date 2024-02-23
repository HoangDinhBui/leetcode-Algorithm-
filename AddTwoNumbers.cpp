#include <iostream>

using namespace std;

void addTwoNums(int listNode1[], int listNode2[], int numOfDigits)
{
    int *sumOfListNode = new int[numOfDigits];
    int firstNum = 0, secondNum = 0, addNum;
    for(int i = numOfDigits - 1; i >= 0; i--)
    {
        firstNum = firstNum * 10;
        firstNum = firstNum + listNode1[i];
    }
    for(int i = numOfDigits - 1; i >= 0; i--)
    {
        secondNum = secondNum * 10;
        secondNum = secondNum + listNode2[i];
    }
   
    addNum = firstNum + secondNum;

    for (int i = 0; i < numOfDigits; i++)
    {
        sumOfListNode[i] = addNum % 10;
        addNum = addNum / 10;
    }
    for (int i = numOfDigits - 1; i >= 0; i--)
        cout << sumOfListNode[i] << " ";
    delete[] sumOfListNode; 
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
    delete[] listNode1;
    delete[] listNode2;
}