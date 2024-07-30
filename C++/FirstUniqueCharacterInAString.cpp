#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        queue<int> queue;
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            queue.push(i);
        }
        
        while (!queue.empty() && count[s[queue.front()]] > 1) {
            queue.pop();
        }
        
        return queue.empty() ? -1 : queue.front();
    }
};

int main() {
    string s;
    cin >> s;
    Solution S;
    cout << "result is: " << S.firstUniqChar(s) << endl;

    return 0;
}