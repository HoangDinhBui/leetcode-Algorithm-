#include <iostream>
 
using namespace std;
 
void result() {
    int countSit = 0, n;
    cin >> n;
    while (n--) {
        int count = 0;
        int A[3];
        for (int i = 0; i < 3; i++)
            cin >> A[i];
        for (int i = 0; i < 3; i++) {
            if (A[i] == 1)
                count++;
        }
        if (count >= 2)
            countSit++;
    }
    cout << countSit << endl;
}
 
int main() {
    result();
    return 0;
}