#include <iostream>

using namespace std;

void result()
{
    int n, count = 0;
    cin >> n;
    int A[1000][1000];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int Position = A[0][0];
            if(A[i+1][j] > A[i][j+1])
            {
                Position = A[i][j+1];
                count++;
            }
            else
            {    
                Position = A[i+1][j];
                count++;
            }
            cout << Position;
        }
    }
    cout << endl << count << endl;;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        result();
    }
}