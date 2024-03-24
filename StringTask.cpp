#include <iostream>
#include <string>

using namespace std;

class StringTask {
private:
    string s;

public:
    StringTask(string s) {
        this->s = s;
    }

    string Task() {
        string A;
        for (int i = 0; i < s.length(); i++) {
            if (tolower(s[i]) != 'u' && tolower(s[i]) != 'e' && tolower(s[i]) != 'o' &&
                tolower(s[i]) != 'a' && tolower(s[i]) != 'i' && tolower(s[i]) != 'y'){
                A += '.';
                if (isupper(s[i])) {
                    A += tolower(s[i]);
                } else {
                    A += s[i];
                }
            }
        }
        return A;
    }
};

int main() {
    string input;
    cin >> input;
    StringTask st(input);
    cout << st.Task();
    return 0;
}
