using System;
using System.Collections;
using System.Collections.Generic;

public class CodeForce13 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            int n = int.Parse(Console.ReadLine());
            List<int> list = new List<int>();
            string[] input = Console.ReadLine().Split();
            for (int j = 0; j < n; j++) {
                list.Add(int.Parse(input[j]));
            }
            int res = countStep(list);  
            Console.WriteLine(res);
        }
    }

    public static int countStep(List<int> list) {
        list.Sort();
        int medianIndex = (list.Count - 1)/2;
        int median = list[medianIndex] + 1;
        int count = 0;
        for(int i = medianIndex; i < list.Count; i++) {
            if(list[i] < median) {
                count += (median - list[i]);
                list[i] = median;
            }
        }
        return count;
    }
}