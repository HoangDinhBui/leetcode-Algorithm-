#include <iostream>

using namespace std;

void result()
{
    long long n, k;
    cin >> n >> k;
    int A[1000], sum = 0, max = 1;
    if(n == k)
        cout << "1\n";
    else if(n > k)
    {
        if(n%k == 0)
            cout << "1\n";
        else
            cout << "2\n";
    }
    else
    {
        long long z = k / n;
        if(k%n)
            z++;
        cout << z << endl;
    }
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