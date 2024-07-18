using System;

public class CodeForce4 {
    public static void Main(string[] args) {
        // Read the number of games
        int n = int.Parse(Console.ReadLine());
        // Read the result of all games in one line
        string s = Console.ReadLine();

        int countA = 0, countD = 0;

        // Iterate through the results to count wins
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A')
                countA++;
            else if(s[i] == 'D')
                countD++;
        }

        // Determine and print the result
        if(countA > countD)
            Console.WriteLine("Anton");
        else if(countA < countD)
            Console.WriteLine("Danik");
        else    
            Console.WriteLine("Friendship");
    }
}
