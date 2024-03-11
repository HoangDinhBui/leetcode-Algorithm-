#include <iostream>

using namespace std;

void equalZero(int *A, int n)
{
    int i;
    
        while(A[i] != 0)
        {
            for(i = n - 1; i >= 2; i--)
            {
            A[i-1] -= 1;
            A[i] -= 2;
            A[i+1] -= 1;
            }
        
        }
}
void result()
{
    int n, i, count = 0;
    cin >> n;
    int *A = new int[n+1];
    for(i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    equalZero(A, n);
    for(i = 1; i <= n; i++)
    {
        if(A[i] == 0)
            count++;
    }
    if(count == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    delete[] A;
}

int main()
{
    int m; 
    cin >> m;
    while(m--)
    {
        result();
    }
    return 0;
}