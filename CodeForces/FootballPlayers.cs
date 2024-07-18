using System;

public class CodeForce2 
{
    public static void Main(string[] args) 
    {
        string input = Console.ReadLine();
        Console.WriteLine(IsDangerous(input) ? "YES" : "NO");
    }

    public static bool IsDangerous(string s) 
    {
        int count0 = 0, count1 = 0;

        foreach(char c in s) 
        {
            if (c == '0') 
            {
                count0++;
                count1 = 0; 
            } 
            else if (c == '1') 
            {
                count1++;
                count0 = 0; 
            }
            
            if (count0 >= 7 || count1 >= 7)
                return true;
        }
        
        return false;
    }
}
