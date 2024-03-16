#include <iostream>

using namespace std;

class ArrayFix
{
private:
    int n;
    int *A;

public:
    ArrayFix()
    {
        n = 2;
        A = new int[2];
    }
    ArrayFix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~ArrayFix()
    {
        delete[] A;
    }
    void result();
    bool isSorted();
};
void ArrayFix::result()
{
    int newValue;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] >= 10)
        {
            newValue = A[i];
            A[i] = newValue / 10;
            A[i + 1] = newValue % 10;
            n++;
            i++;
        }
    }

    if (isSorted())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

bool ArrayFix::isSorted()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int d;
    cin >> d;
    ArrayFix ar(d);
    int t;
    cin >> t;
    while (t--)
    {
        ar.result();
    }
    return 0;
}
