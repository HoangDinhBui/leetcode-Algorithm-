using System;
using System.Collections.Generic;
using System.Linq;

public class CodeForce18
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine()); // Đọc số lượng bộ dữ liệu
        const long MOD = 1000000007; // Hằng số mod

        for (int i = 0; i < t; i++)
        {
            // Đọc số lượng bông hoa và số tiền có được
            var inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int n = inputs[0];
            long m = inputs[1];

            // Đọc số lượng cánh hoa và sắp xếp
            List<int> petals = Console.ReadLine().Split().Select(int.Parse).ToList();
            petals.Sort();

            long currentSum = 0;
            long maxPetals = 0;
            int start = 0;

            // Duyệt bằng hai con trỏ
            for (int end = 0; end < n; ++end)
            {
                currentSum += petals[end];

                // Nếu tổng số tiền vượt quá m, dịch chuyển con trỏ start
                while (currentSum > m && start <= end)
                {
                    currentSum -= petals[start];
                    start++;
                }

                // Cập nhật số lượng cánh hoa tối đa nếu hợp lệ
                if (currentSum <= m)
                {
                    // (end - start + 1) là số lượng bông hoa trong đoạn
                    // petals[end] là số lượng cánh hoa của bông hoa cuối cùng trong đoạn
                    maxPetals = Math.Max(maxPetals, (end - start + 1) * petals[end]);
                }
            }

            // In kết quả cho bộ dữ liệu hiện tại
            Console.WriteLine(maxPetals);
        }
    }
}
