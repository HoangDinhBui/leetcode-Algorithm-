using System;

public class MatrixStabilization
{
    public static void Main(string[] args)
    {
        int t = int.Parse(Console.ReadLine());  // Đọc số lượng bộ dữ liệu

        for (int test = 0; test < t; test++)
        {
            string[] dimensions = Console.ReadLine().Split();
            int n = int.Parse(dimensions[0]);  // Số dòng
            int m = int.Parse(dimensions[1]);  // Số cột

            int[,] matrix = new int[n, m];

            // Đọc dữ liệu cho ma trận
            for (int i = 0; i < n; i++)
            {
                string[] row = Console.ReadLine().Split();
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = int.Parse(row[j]);
                }
            }

            bool okay = true;

            // Lặp lại quá trình cho đến khi không có thay đổi
            while (okay)
            {
                okay = false;
                int up, down, left, right;

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        // Lấy giá trị từ các ô lân cận
                        if (i > 0) up = matrix[i - 1, j];
                        else up = 0;

                        if (j > 0) left = matrix[i, j - 1];
                        else left = 0;

                        if (i < n - 1) down = matrix[i + 1, j];
                        else down = 0;

                        if (j < m - 1) right = matrix[i, j + 1];
                        else right = 0;

                        // Tìm giá trị lớn nhất trong các ô lân cận
                        int maxNeighbor = Math.Max(Math.Max(up, down), Math.Max(left, right));

                        // Nếu giá trị của ô hiện tại lớn hơn maxNeighbor, cập nhật nó
                        if (matrix[i, j] > maxNeighbor)
                        {
                            matrix[i, j] = maxNeighbor;
                            okay = true;  // Đặt cờ để tiếp tục quá trình
                        }
                    }
                }
            }

            // In ra ma trận đã ổn định
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

//Giải thích chương trình:
// Input và Parsing:

// Chương trình bắt đầu bằng việc đọc số lượng bộ dữ liệu (t).
// Sau đó, nó đọc kích thước của ma trận (số dòng n và số cột m).
// Ma trận được điền dữ liệu từ input.
// Quá trình ổn định:

// Sử dụng vòng lặp while để tiếp tục quá trình cho đến khi không có thay đổi nào xảy ra trong ma trận.
// Duyệt qua từng ô của ma trận để tính toán giá trị lớn nhất của các ô lân cận.
// Nếu giá trị của ô hiện tại lớn hơn giá trị lớn nhất của các ô lân cận, giá trị của ô sẽ được cập nhật.
// Output:

// Cuối cùng, chương trình in ra ma trận đã ổn định.