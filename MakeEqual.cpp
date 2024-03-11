#include <iostream>

using namespace std;

bool checkMakeEqual() 
{
    int n;
    cin >> n;
    if (n < 1 || n > 2e5) {
        return false;
    }
    int A[200000];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += A[i];
    }
    if (sum % n != 0)
        return false;
    else
    {
        int avg = sum / n;
        for (int i = 0; i < n; ++i) {
            if (A[i] != avg) {
                int diff = avg - A[i];
                if(A[i] - diff > 0)
                {
                    A[i] += diff;
                    A[i + 1] -= diff;
                }
                else    
                    return false;
            }
        }
        return true;
    }
    return true;
}

int main() 
{
    int m;
    cin >> m;
    while(m--)
    {
        if (checkMakeEqual())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }
    return 0;
}