using System;
using System.Collections.Generic;
using System.Linq;

public class CodeForce8
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());
        while (t > 0)
        {
            var input = Console.ReadLine().Split();
            int n = int.Parse(input[0]);
            int f = int.Parse(input[1]) - 1;  // Chỉ số bắt đầu từ 0
            int k = int.Parse(input[2]);
            var a = Console.ReadLine().Split().Select(int.Parse).ToList();
            
            int favourite = a[f];
            a.Sort((x, y) => y.CompareTo(x)); // Sắp xếp giảm dần

            var removed = a.Take(k).ToList(); // Lấy k phần tử đầu tiên của List a
            var remaining = a.Skip(k).ToList(); // Các phần tử còn lại sau khi bỏ k phần tử

            if (removed.Contains(favourite) && !remaining.Contains(favourite))
            {
                // Khối lập phương yêu thích đã bị loại bỏ
                Console.WriteLine("YES");
            }
            else if (remaining.Contains(favourite) && removed.Contains(favourite))
            {
                // Khối lập phương yêu thích không bị loại bỏ
                Console.WriteLine("MAYBE");
            }
            else
            {
                // Nếu không nằm trong cả hai trường hợp, có thể có hoặc không bị loại bỏ
                Console.WriteLine("NO");
            }

            t--;
        }
    }
}
