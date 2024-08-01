using System;
using System.Collections.Generic;
using System.Linq;

public class CodeForce17 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        while (t-- > 0) {
            int n = int.Parse(Console.ReadLine());
            List<long> list = Console.ReadLine().Split().Select(long.Parse).ToList();

            long ans = 0, sum = 0, mx = 0;

            for (int j = 0; j < n; j++) {
                mx = Math.Max(mx, list[j]);
                sum += list[j];
                if (mx == sum - mx) {
                    ans++;
                }
            }

            Console.WriteLine(ans);
        }
    }
}
