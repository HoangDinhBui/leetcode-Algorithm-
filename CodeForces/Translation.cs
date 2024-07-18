using System;
using System.Collections;

public class CodeForce5 {
    public static void Main(string[] args) {
        string s1 = Console.ReadLine();
        string s2 = Console.ReadLine();
        string tryS2 =Translation(s1);
        int result = String.Compare(s2, tryS2, StringComparison.OrdinalIgnoreCase);

        if(result == 0)
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }

    public static string Translation(string s) {
        string res = string.Empty;
        Stack<char> stack = new Stack<char>();
        for(int i = 0; i < s.Length; i++) {
            stack.Push(s[i]);
        }
        int size = stack.Count;
        while(size > 0) {
            res += stack.Peek();
            stack.Pop();
            size--;
        }
        return res;
    }
}