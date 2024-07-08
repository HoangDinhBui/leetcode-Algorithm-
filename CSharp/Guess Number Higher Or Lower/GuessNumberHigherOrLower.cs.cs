using System;
public class Solution10 : GuessGame
{
    public Solution10(int number) : base(number)
    {
    }

    public int GuessNumber(int n)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int tmp = guess(m);
            if (tmp == 0)
                return m;
            else if (tmp == -1)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
}
