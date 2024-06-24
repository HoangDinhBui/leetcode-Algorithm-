public class Solution2 {
    public void ReverseString(char[] s) {
        Stack<char> stack = new Stack<char>();
        foreach(char c in s) 
            stack.Push(c);
        for(int i = 0; i < s.Length; i++){
            s[i] = stack.Pop();
        }
    }
}