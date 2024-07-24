using System;
using System.Collections;

public class CodeForce12 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            int n = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();
            string r = new string(s.Distinct().OrderBy(c => c).ToArray());
            Dictionary<char, char> decodeMap = new Dictionary<char, char>();
            int len = r.Length;
            for(int j = 0; j < len; j++) {
                decodeMap[r[len - j - 1]] = r[j]; 
            }
            char[] decode = new char[n];
            for(int j = 0; j < n; j++) {
                decode[j] = decodeMap[s[j]];
            }
            Console.WriteLine(new string(decode));
        }
    }
}