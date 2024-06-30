public class Solution5 {
    public int[] Intersect(int[] nums1, int[] nums2) {
        List<int> intersection = new List<int>();
        bool[] isMapped = new bool[nums1.Length];

        for(int i = 0; i < nums2.Length; i++) {
            for(int j = 0; j < nums1.Length; j++) {
                if(nums2[i] == nums1[j] && !isMapped[j]) {
                    intersection.Add(nums2[i]);
                    isMapped[j] = true;
                    break;
                }
            }
        }
        return intersection.ToArray();
    }
}