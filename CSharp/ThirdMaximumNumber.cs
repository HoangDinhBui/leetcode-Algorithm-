public class Solution9 {
    public int ThirdMax(int[] nums) {
        Array.Sort(nums);
        Array.Reverse(nums);

        int distinctCount = 0;
        int currentMax = nums[0];
        
        foreach (int num in nums) {
            if (num != currentMax) {
                distinctCount++;
                currentMax = num;
            }
            if (distinctCount == 2) {
                return num;
            }
        }

        return nums[0];
    }
}
