public class Program {
    public static void Main(string[] args) {
        Solution4 solution = new Solution4();
        
        // Test cases
        string input1 = "hello";
        string input2 = "leetcode";
        
        string result1 = solution.ReverseVowels(input1);
        string result2 = solution.ReverseVowels(input2);
        
        Console.WriteLine($"Original: {input1} -> Reversed Vowels: {result1}");
        Console.WriteLine($"Original: {input2} -> Reversed Vowels: {result2}");
    }