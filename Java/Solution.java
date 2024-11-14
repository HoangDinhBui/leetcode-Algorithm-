import java.util.Scanner;

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        return Integer.reverse(n);
    }
    
    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        Solution solution = new Solution();
        System.out.println(solution.reverseBits(n));
    }
}