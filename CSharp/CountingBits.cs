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

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        int n = 5;  // Bạn có thể thay đổi giá trị này để kiểm tra các đầu vào khác nhau
        int[] result = solution.CountBits(n);
        Console.WriteLine(string.Join(", ", result));  // Output: 0, 1, 1, 2, 1, 2
    }
}
