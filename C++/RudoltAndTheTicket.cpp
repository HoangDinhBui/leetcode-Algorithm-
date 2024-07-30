#include <iostream>

using namespace std;

int result()
{
    int n, m, k, i, j, count = 0;
    cin >> n >> m >> k;
    int *B = new int[n];
    int *C = new int[m];
    for(i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for(i = 0; i < m; i++)
    {
        cin >> C[i];
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(B[i] + C[j] <= k)
                count++;
        }
    }
    delete[] B;
    delete[] C;
    return count;
}

int main()
{
    int h;
    cin >> h;
    while(h--)
    {
        cout << result() << endl;
    }
    return 0;
}