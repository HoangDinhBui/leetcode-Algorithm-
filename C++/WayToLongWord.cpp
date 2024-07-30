#include <iostream>
#include <string>
using namespace std;
 
string abbreviate(const string& word)
{
    if (word.length() > 10) 
    {
        return word[0] + to_string(word.length() - 2) + word.back();
    }
    return word;
}
 
int main() 
{
    int n;
    cin >> n;
    cin.ignore(); 
 
    for (int i = 0; i < n; ++i) {
        string word;
        getline(cin, word);
        cout << abbreviate(word) << endl;
    }
    return 0;
}