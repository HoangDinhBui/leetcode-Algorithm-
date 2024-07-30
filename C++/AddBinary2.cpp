#include <iostream>

using namespace std;

void splitNum(int n, int *binary, int &count)
{
    int i = 0;
    while(n > 0)
    {
        binary[i] = n%10;
        n = n/10;
        i++;    
    }
    count = i;
}

void sumBinary(int *binaryA, int *binaryB, int *binarySum, int count)
{
    for(int i = count - 1; i > 0; i--)
    {
        if(binaryA[i] == 0 && binaryB[i] == 1)
        {
            binarySum[i] = 1;
            continue;
        }
        if(binaryA[i] == 1 && binaryB[i] == 0)
        {
            binarySum[i] = 1;
            continue;
        }
        if(binaryA[i] == 0 && binaryB[i] == 0)
        {
            binarySum[i] = 0;
            continue;
        }
        if(binaryA[i] == 1 && binaryB[i] == 1)
        {
            if(binaryA[i-1] == 1 && binaryB[i-1] == 1)
            {
                binarySum[i] = 0;
                binarySum[i-1] = 1;
            }
            else
                binarySum[i] = 1;
        }
    }
}

int main()
{
    int num1, num2, count1 = 0, count2 = 0;
    cout << "Enter two number need to add: ";
    cin >> num1 >> num2;
    int binaryA[10] = {0}; //= new int[10];
    int binaryB[10] = {0}; //= new int[10];
    int binarySum[10] = {0}; //= new int[10];
    splitNum(num1, binaryA, count1);
    splitNum(num2, binaryB, count2);
    if(count1 > count2)
        sumBinary(binaryA, binaryB, binarySum, count1);
    else
        sumBinary(binaryA, binaryB, binarySum, count2);
    for(int i = 0; i < count1+count2; i++)
    {
        cout << binarySum[i] << " ";
    }
}