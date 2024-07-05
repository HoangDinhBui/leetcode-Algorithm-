public class Solution6 {
    public bool IsPerfectSquare(int num) {
        if(num < 2) return true;
        int l = 2, r = num / 2;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long square = (long)mid * mid;
            if(square == num) {
                return true;
            } else if(square > num) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
}