#include <iostream>
#include <string>

using namespace std;

int minCharsToRemove(string s) {
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n - 2; ++i) {
        if ((s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') || 
            (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')) {
            count++;
            i += 2; 
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << minCharsToRemove(s) << endl;
    }

    return 0;
}
