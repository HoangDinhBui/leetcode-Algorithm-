#include <iostream>

using namespace std;

class Solution {
    public:
        bool CanWinNim(int n) {
            return n % 4 != 0;
        }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.CanWinNim(n) << endl;

    return 0;
}