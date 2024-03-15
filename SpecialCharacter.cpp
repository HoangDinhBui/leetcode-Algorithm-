#include <iostream>
#include <string>

using namespace std;

void result()
{
    int n;
    cin >> n;
    if (n % 2 == 1 || n < 2) 
    {
        cout << "NO" << endl;
    } 
    else 
    {
        cout << "YES" << endl;
        string special_string = "";
        for (int i = 0; i < n/2; ++i) 
        {
            special_string += "AAB";
        }
        cout << special_string << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
       result();
    }
    return 0;
}
