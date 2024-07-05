public class Solution7 {
    public bool CanConstruct(string ransomNote, string magazine) {
        if(ransomNote.Length > magazine.Length) 
            return false;
        int[] countChar = new int[27];
        foreach(char c in magazine) 
            countChar[c - 'a']++;
        foreach(char c in ransomNote) {
            if(countChar[c - 'a'] == 0) 
                return false;
            countChar[c - 'a']--;
        }
        return true;    
    }
}