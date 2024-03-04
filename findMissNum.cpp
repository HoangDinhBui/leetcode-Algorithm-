#include <iostream>

using namespace std;

int findMissNum(int A[], int n)
{
    int low = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] != low + i)
            return low + i;
    }
    return 0;
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
    cout << "Missing number is: " << findMissNum(A, n) << endl;
    delete[] A;
    return 0;
}