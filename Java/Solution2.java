import java.util.HashMap;
import java.util.Map;

class Solution2 {
    public int[] singleNumber(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int num : nums) mp.put(num, mp.getOrDefault(num, 0) + 1);
        
        int[] res = new int[2];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() == 1) res[index++] = entry.getKey();
        }
        return res;
    }
}