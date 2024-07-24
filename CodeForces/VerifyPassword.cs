using System;
using System.Collections.Generic;

public class CodeForce11 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            if(checkStrongPassWord(s))
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
    }

    public static bool checkStrongPassWord(string s) {
        for(int i = 0; i < s.Length - 1; i++) {
            if(char.IsLetter(s[i]) && char.IsDigit(s[i+1]))
                return false;
        }
        string digits = new string(s.Where(char.IsDigit).ToArray());
        string letters = new string(s.Where(char.IsLetter).ToArray());

        bool isSortedDigit = digits == string.Concat(digits.OrderBy(c => c));
        bool isSortedLetter = letters == string.Concat(letters.OrderBy(c => c));

        return isSortedDigit && isSortedLetter;
    }
}