using System;

public class CodeForce10 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++) {
            var input = Console.ReadLine().Split();
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            
            // Kiểm tra điều kiện
            if (m <= n && (n - m) % 2 == 0) {
                Console.WriteLine("Yes");
            } else {
                Console.WriteLine("No");
            }
        }
    }
}
