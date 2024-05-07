#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        long long res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            long long h = min(height[l], height[r]); // Change data type to long long
            int w = r - l;
            long long v = h * w;
            res = max(res, v);
            if (height[l] < height[r])
                l++;
            else 
                r--; // Corrected increment
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example height array
    cout << "Maximum area: " << solution.maxArea(height) << endl;
    return 0;
}
