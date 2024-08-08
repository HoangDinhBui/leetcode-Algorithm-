using System;

public class CodeForce20 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++) {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();

            // Nếu hai chuỗi đã bằng nhau
            if (s1.Equals(s2)) {
                Console.WriteLine("YES");
                continue;
            }
            
            bool isEqual = false;
            for (int j = 0; j < s1.Length - 1; j++) {
                if (s1[j] == '0' && s1[j + 1] == '1' && s2[j] == '0' && s2[j + 1] == '1') {
                    isEqual = true;
                    break;
                }
            }

            if (isEqual) 
                Console.WriteLine("YES");
            else 
                Console.WriteLine("NO");
        }
    }
}
