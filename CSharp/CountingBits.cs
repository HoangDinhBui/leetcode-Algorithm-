using System;
using System.Linq;

public class Solution {
    public int[] CountBits(int n) {
        int[] ans = new int[n + 1];  // Khởi tạo mảng với kích thước n + 1
        for (int i = 0; i <= n; i++) {
            string binary = Convert.ToString(i, 2);
            ans[i] = binary.Count(c => c == '1');
        }
        return ans;
    }
}

