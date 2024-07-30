#include <iostream>

using namespace std;

void findMissNum(int A[], int n)
{
    int diff = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] != diff + i)    
        {
            while(diff < A[i] - i)
            {
                cout << diff + i <<" ";
                diff++;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    findMissNum(A, n);
    delete[] A;
    return 0;
}