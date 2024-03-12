#include <iostream>
#include <cmath>

using namespace std;

int result()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(((4*n)-2) == k)
        ans = ceil(k/2)+1;
    else
        ans = ceil(k/2);
    cout << ans << endl;
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