using System;
using System.Collections.Generic;

public class CodeForce1
{
    public static void Main()
    {
        // Đọc dữ liệu từ đầu vào
        int n = int.Parse(Console.ReadLine());
        var coins = new List<(int x, int y)>();
        for (int i = 0; i < n; i++)
        {
            var line = Console.ReadLine().Split();
            int x = int.Parse(line[0]);
            int y = int.Parse(line[1]);
            coins.Add((x, y));
        }
        
        // Tính toán và in kết quả
        var results = CanCollectCoins(n, coins);
        foreach (var result in results)
        {
            Console.WriteLine(result);
        }
    }
    
    public static List<string> CanCollectCoins(int n, List<(int x, int y)> coins)
    {
        var results = new List<string>();
        foreach (var (x, y) in coins)
        {
            // Khoảng cách Manhattan từ (0, 0) đến (x, y)
            int distance = Math.Abs(x) + Math.Abs(y);
            // Kiểm tra nếu khoảng cách này nhỏ hơn hoặc bằng y
            if (distance <= y)
            {
                results.Add("YES");
            }
            else
            {
                results.Add("NO");
            }
        }
        return results;
    }
}
