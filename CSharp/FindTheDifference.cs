public class Solution12 {
    public char FindTheDifference(string s, string t) {
        char res = '\0';
        foreach(char c in s) 
            res ^= c;
        foreach(char c in t) 
            res ^= c;
        return res;
    }
}