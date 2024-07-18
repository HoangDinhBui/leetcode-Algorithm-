using System;

class CodeForce3
{
    static void Main()
    {
        string input = Console.ReadLine();
        
        string n = input;
        
        int countLuckyDigits = 0;
        foreach (char digit in n)
        {
            if (digit == '4' || digit == '7')
            {
                countLuckyDigits++;
            }
        }
        if (countLuckyDigits == 0)
        {
            Console.WriteLine("NO");
            return;
        }
        string strCount = countLuckyDigits.ToString();
        foreach (char digit in strCount)
        {
            if (digit != '4' && digit != '7')
            {
                Console.WriteLine("NO");
                return;
            }
        }

        Console.WriteLine("YES");
    }
}
