#include <iostream>
#include <math.h>

using namespace std;

int count01(int n, int *binary)
{
    int count = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(binary[i] == 0 && binary[i+1] == 1)
            {
                count++;
            }
        }
    return count;
}

void checkBinary(int n, int *binary)
{
    for(int i = n - 1; i >= 0; i--)
    {
        if(binary[i] == 0)
        {
            binary[i] = 1;
            break;
        }
        else
            binary[i] = 0;
    }
}

void printBinaryList(int n, int *binary)
{
    for(int i = 0; i < n; i++)
    {
        cout << binary[i];
    }
    cout << endl;
}

int main()
{
    int n, count = 0;
    cin >> n;
    int *binary = new int[n]();
    for(int i = 0; i < pow(2, n); i++)
    {
        if(count01(n, binary) == 2)
        {
            printBinaryList(n, binary);
        }
        checkBinary(n, binary);
    }
    system("pause");
    delete[] binary;
    return 0;
}