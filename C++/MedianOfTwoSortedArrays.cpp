#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int size = nums1.size() + nums2.size();
        for(int i = 0; i < nums1.size(); i++)
            nums.push_back(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            nums.push_back(nums2[i]);
        sort(nums.begin(), nums.end());
        if(size % 2 != 0)
            return nums[size/2];
        else
            return (nums[size/2-1] + nums[size/2])/2.0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {1};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {2};
    nums2 = {};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
