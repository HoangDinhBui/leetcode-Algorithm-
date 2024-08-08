using System;

public class CodeForce21
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());
        for (int test = 0; test < t; test++)
        {
            string[] dimensions = Console.ReadLine().Split();
            int n = int.Parse(dimensions[0]);
            int m = int.Parse(dimensions[1]);

            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                string[] row = Console.ReadLine().Split();
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = int.Parse(row[j]);
                }
            }

            bool changed;
            do
            {
                changed = false;
                int[,] newMatrix = (int[,])matrix.Clone();

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        int maxAdjacent = matrix[i, j];

                        if (i > 0) maxAdjacent = Math.Max(maxAdjacent, matrix[i - 1, j]);
                        if (i < n - 1) maxAdjacent = Math.Max(maxAdjacent, matrix[i + 1, j]);
                        if (j > 0) maxAdjacent = Math.Max(maxAdjacent, matrix[i, j - 1]);
                        if (j < m - 1) maxAdjacent = Math.Max(maxAdjacent, matrix[i, j + 1]);

                        if (maxAdjacent > matrix[i, j])
                        {
                            newMatrix[i, j] = maxAdjacent;
                            changed = true;
                        }
                    }
                }

                matrix = newMatrix;
            } while (changed);

            // In ma trận đã ổn định
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}

