#include <iostream>
#include <string>

using namespace std;

class BoyOrGirl {
private:
    string A;
public:
    BoyOrGirl(string s) {
       A = s;
    }
    void result();
};

void BoyOrGirl :: result() {
    int count = 0;
    for (int i = 0; i < A.length(); i++) {
        bool isUnique = false;
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                isUnique = true;
                break;
            }
        }
        if (!isUnique) {
            count++;
        }
    }
    if (count % 2 == 0)
        cout << "CHAT WITH HER!";
    else        
        cout << "IGNORE HIM!";
}

int main() {
    string A;
    cin >> A;
    BoyOrGirl b(A);
    b.result();
    return 0;
}
