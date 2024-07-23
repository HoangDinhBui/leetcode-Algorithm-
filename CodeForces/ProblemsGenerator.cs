using System;
using System.Collections.Generic;
using System.Linq;

public class CodeForce9 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int testCase = 0; testCase < t; testCase++) {
            var input = Console.ReadLine().Split();
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            string a = Console.ReadLine();
            
            var difficultyCount = new Dictionary<char, int> {
                {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
                {'E', 0}, {'F', 0}, {'G', 0}
            };

            // Đếm số lượng mỗi mức độ khó trong danh sách bài toán hiện tại
            foreach (char ch in a) {
                if (difficultyCount.ContainsKey(ch)) {
                    difficultyCount[ch]++;
                }
            }

            int problemsNeeded = 0;
            foreach (var kvp in difficultyCount) {
                int required = m - kvp.Value;
                if (required > 0) {
                    problemsNeeded += required;
                }
            }
            
            Console.WriteLine(problemsNeeded);
        }
    }
}
