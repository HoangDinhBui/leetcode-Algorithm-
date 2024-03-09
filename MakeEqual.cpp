#include <iostream>

using namespace std;

bool checkMakeEqual(int *A, int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += A[i];
    }
    if (sum % n != 0)
        return false;

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

int main() 
{
    int n;
    cin >> n;
    int *A = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    if (checkMakeEqual(A, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    delete[] A;
    return 0;
}
