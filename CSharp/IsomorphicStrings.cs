public class Solution3 {
    public bool IsIsomorphic(string s, string t) {
        Dictionary<int, char> mapSToT = new Dictionary<int, char>();
        Dictionary<int, char> mapTToS = new Dictionary<int, char>();
        if(s.Length != t.Length) return false;
        for(int i = 0; i < s.Length; i++) {
            char charS = s[i];
            char charT = t[i];
            if(mapSToT.ContainsKey(charS)) {
                if(mapSToT[charS] != charT) return false;
            } else mapSToT[charS] = charT; 
            if(mapTToS.ContainsKey(charT)) {
                if(mapTToS[charT] != charS) return false;
            } else mapTToS[charT] = charS;
        }
        return true;
    }
}