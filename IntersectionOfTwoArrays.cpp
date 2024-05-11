#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mp;
    
        // Tạo bản đồ đếm số lần xuất hiện của từng phần tử trong nums1
        for (int num : nums1) {
            mp[num]++;
        }
        
        // Duyệt qua nums2, nếu phần tử này đã xuất hiện trong mp và chưa được thêm vào kết quả, thêm vào kết quả
        for (int num : nums2) {
            if (mp[num] > 0) {
                result.push_back(num);
                // Đánh dấu đã thêm vào kết quả để tránh thêm phần tử trùng lặp
                mp[num] = 0;
            }
        }
        
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 2, 3, 4};
    
    Solution solution;
    vector<int> intersectionResult = solution.intersection(nums1, nums2);
    
    cout << "Phan tu giao cua hai vector la: ";
    for (int num : intersectionResult) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
