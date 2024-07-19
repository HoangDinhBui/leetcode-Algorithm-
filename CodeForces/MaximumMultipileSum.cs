//output = x + 2x + 3x +... || output <= n
using System;

public class CodeForce6 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        List<int> results = new List<int>();
        for(int i = 0; i < t; i++) {
            int n = int.Parse(Console.ReadLine());
            int maximum = 0;
            int optimalX = 2;
            for(int x = 2; x <= n; x++) {
                int total = 0;
                for(int k = 1; k * x <= n; k++) {
                    total += k * x;
                }
                if(total > maximum) {
                    maximum = total;
                    optimalX = x;
                }
            }
            results.Add(optimalX);
        }
        foreach(int result in results) 
            Console.WriteLine(result);
    }
}