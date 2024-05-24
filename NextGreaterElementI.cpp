#include <vector>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> stack;
        map<int, int> nextGreater;
        for(int i = 0; i < nums2.size(); i++) {
            while(!stack.empty() && stack.top() <  nums2[i]) {
                nextGreater[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(nextGreater[nums1[i]]) res[i] = nextGreater[nums1[i]];
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution s;
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for(int num : res) {
        cout << num << " ";
    }
    return 0;
}