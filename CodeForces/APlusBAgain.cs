using System;

public class CodeForce23 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            int n = int.Parse(Console.ReadLine());

            int res = n % 10 + n / 10;
            Console.WriteLine(res);
        }
    }
}