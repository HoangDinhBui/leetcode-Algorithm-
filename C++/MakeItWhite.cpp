#include <iostream>

using namespace std;

void makeWhiteColor()
{
    int n;
    cin >> n;
    char A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int Count1 = 1, Count2 = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i] == 'W')
            Count1++;
        else break;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(A[i] == 'W')
            Count2++;
        else break;
    }
    if(A[0] == 'W' && A[n - 1] == 'W')
    {
        if(Count1 + Count2 > n)
            cout << 0 << endl;
        else 
            cout << n - Count1 - Count2 << endl;
    }
    else if(A[0] == 'W')
    {
        cout << n - Count1 << endl;
    }
    else if(A[n-1] == 'W')
        cout << n - Count2 << endl;
    else    
        cout << n << endl;
}

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        makeWhiteColor();
    }
    return 0;
}