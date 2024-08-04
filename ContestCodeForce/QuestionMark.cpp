#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans;
        cin >> ans;

        int countA = 0, countB = 0, countC = 0, countD = 0, countQ = 0;

        for (char c : ans) {
            if (c == 'A') countA++;
            else if (c == 'B') countB++;
            else if (c == 'C') countC++;
            else if (c == 'D') countD++;
            else if (c == '?') countQ++;
        }

        int correct = min(countA, n) + min(countB, n) + min(countC, n) + min(countD, n);

        // int neededA = max(0, n - countA);
        // int neededB = max(0, n - countB);
        // int neededC = max(0, n - countC);
        // int neededD = max(0, n - countD);

        // int totalNeeded = neededA + neededB + neededC + neededD;

        // if (countQ >= totalNeeded) {
        //     correct += totalNeeded;
        //     countQ -= totalNeeded;
        // } else {
        //     correct += countQ;
        //     countQ = 0;
        // }

        // correct += countQ / 4;

        cout << correct << endl;
    }
    return 0;
}
