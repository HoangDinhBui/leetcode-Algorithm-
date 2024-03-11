#include <iostream>

using namespace std;

void makeEqualTime()
{
    int n;
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int Count1 = 1, Count2 = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i] == A[0])
            Count1++;
        else break;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(A[i] == A[n - 1])
            Count2++;
        else break;
    }
    if(A[0] == A[n - 1])
    {
        if(Count1 + Count2 > n)
            cout << 0 << endl;
        else
            cout << n - Count1 - Count2 << endl;
    }
    else
    {
        if(Count1 < Count2) cout << n - Count2 << endl;
        else cout << n - Count1 << endl;
    }
    delete[] A;
}

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        makeEqualTime();
    }
    return 0;
}