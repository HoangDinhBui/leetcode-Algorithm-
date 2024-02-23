#include <iostream>

using namespace std;

int powOfTwo(int n)
{
    int s = 1;
    for(int i = n; i > 0; i--)
    {
        s = s * 2;
    }
    return s;
}

bool isPowerOfTwo(int n)
{
    int count = 0;
    if(n <= 0)
        return false;
    if(n == 1)
        return true;
    int s = 0;
    for(int i = 1; i <= n/2; i++)
    {
        if (n == powOfTwo(i))
            count++;
        continue;
    }
    if(count == 0)   
        return false;
    return true; 
}

int main()
{
    int n;
    cin >> n;
    if (isPowerOfTwo(n) == true)
        cout << "True";
    else
        cout << "False";
    return 0;
}