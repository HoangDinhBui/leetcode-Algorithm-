using System;

public class CodeForce7 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++) {
            string[] inputs = Console.ReadLine().Split(' ');
            string a = inputs[0];
            string b = inputs[1];

            char[] aArr = a.ToCharArray();
            char[] bArr = b.ToCharArray();

            char tmp = aArr[0];
            aArr[0] = bArr[0];
            bArr[0] = tmp;

            a = new string(aArr);
            b = new string(bArr);

            Console.WriteLine(a + " " + b);
        }
    }
}
