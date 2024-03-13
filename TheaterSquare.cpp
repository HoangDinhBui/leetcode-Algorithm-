#include <iostream>

using namespace std;

void result()
{
    long long n, m, a;
    cin >> n >> m >> a;
    long long flagstones = ((n + a - 1) / a) * ((m + a - 1) / a);
    cout << flagstones << endl;
}

int main()
{
    result();
}