using System;

public class CodeForce22 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            string[] input = Console.ReadLine().Split();
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            int k = int.Parse(input[2]);

            Console.WriteLine(Math.Min(n, k) * Math.Min(m, k));
        }
    }
}