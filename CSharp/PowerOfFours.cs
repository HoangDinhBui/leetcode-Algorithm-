using System;
using System.Linq;

public class Solution1 {
    public bool IsPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
}