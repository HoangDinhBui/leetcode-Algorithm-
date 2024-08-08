using System;
using System.Collections.Generic;

public class CodeForce19 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < t; i++) {
            string[] dimensions = Console.ReadLine().Split();
            int n = int.Parse(dimensions[0]);
            int m = int.Parse(dimensions[1]);

            int[,] a = new int[n, m];

            for (int j = 0; j < n; j++) {
                string[] row = Console.ReadLine().Split();
                for (int k = 0; k < m; k++) {
                    a[j, k] = int.Parse(row[k]);
                }
            }

            if (n == 1 && m == 1) {
                Console.WriteLine("-1");
                continue;
            }

            List<int> values = new List<int>();
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    values.Add(a[j, k]);
                }
            }

            values.Sort();

            int[,] b = new int[n, m];
            bool possible = false;

            for (int shift = 1; shift < values.Count; shift++) {
                int index = 0;
                bool conflict = false;

                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        b[j, k] = values[(index + shift) % values.Count];
                        if (b[j, k] == a[j, k]) {
                            conflict = true;
                            break;
                        }
                        index++;
                    }
                    if (conflict) break;
                }

                if (!conflict) {
                    possible = true;
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < m; k++) {
                            Console.Write(b[j, k] + " ");
                        }
                        Console.WriteLine();
                    }
                    break;
                }
            }

            if (!possible) {
                Console.WriteLine("-1");
            }
        }
    }
}
