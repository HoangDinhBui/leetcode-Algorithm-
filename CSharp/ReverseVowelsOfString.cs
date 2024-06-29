public class Solution4 {
    public string ReverseVowels(string s) {
        int l = 0, r = s.Length - 1;
        char[] chars = s.ToCharArray();
        string vowels = "aeiouAEIOU";
        
        while (l < r) {
            while (l < r && !vowels.Contains(chars[l])) {
                l++;
            }
            while (l < r && !vowels.Contains(chars[r])) {
                r--;
            }
            if (l < r) {
                char tmp = chars[l];
                chars[l] = chars[r];
                chars[r] = tmp;
                l++;
                r--;
            }
        }
        return new string(chars);
    }
}
