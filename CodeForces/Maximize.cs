using System;

public class CodeForce15 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++) {
            int x = int.Parse(Console.ReadLine());
            int bestY = 1; 
            int maxResult = 1 + GCD(x, 1); 

            for (int y = 2; y < x; y++) {
                int currentResult = y + GCD(x, y);
                if (currentResult > maxResult) {
                    maxResult = currentResult;
                    bestY = y;
                }
            }

            Console.WriteLine(bestY);
        }
    }

    public static int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
