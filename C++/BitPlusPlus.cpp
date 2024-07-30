#include <iostream>
#include <string>

using namespace std;

void result()
{
    int n;
    cin >> n;
    int x = 0;
    string input;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        if(input == "X++" || input == "++X")
            x++;
        else if(input == "X--" || input == "--X")
            x--;
    }
    cout << x << endl;
}
int main()
{
    result();
}