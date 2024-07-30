#include <iostream>
#include <cmath>
using namespace std;

void exchangeToBinary(int n, int *binary)
{
    int i = 0;
    while (n > 0)
    {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
}

int exchangeToDecimal(int count, int *binary)
{
    int s = 0;
    for(int i = 0; i < count; i++)
    {
        s = s + binary[i] * pow(2, i);
    }
    return s;
}

void splitNum(int n, int &count, int *binary)
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

int main()
{
    int a, b, count1 = 0, count2 = 0;
    int binary1[10] = {0};
    int binary2[10] = {0};
    int binarySum[20] = {0};
    cout << "Enter a and b: ";
    cin >> a >> b;
    splitNum(a, count1, binary1);
    splitNum(b, count2, binary2);
    int decimalA = exchangeToDecimal(count1, binary1);
    int decimalB = exchangeToDecimal(count2, binary2);
    int s = decimalA + decimalB;
    exchangeToBinary(s, binarySum);
    
    for (int i = count1 + count2 - 1; i >= 0; i--)
    {
        cout << binarySum[i];
    }
    cout << endl;
    return 0;
}
