using System;
using System.Collections;

public class CodeForce14 {
    public static void Main(string[] args) {
        int t = int.Parse(Console.ReadLine());
        for(int i = 0; i < t; i++) {
            string[] input = Console.ReadLine().Split();
            int introvert = int.Parse(input[0]);
            int extrovert = int.Parse(input[1]);
            int universal = int.Parse(input[2]);
            int res = introvert;
            int r = extrovert % 3; //Số người hướng ngoại dư ra khi chia lều
            if(r == 0) {
                res += extrovert / 3;//Nếu số lều còn thiếu là bằng 0 thì cộng số lều đã đủ cho res
                if(universal % 3 == 0) 
                    res += universal / 3;
                else 
                    res += universal / 3 + 1;
                Console.WriteLine(res);
            } else if(universal >= 3 - r) { //Kiểm tra số người linh hoạt có đủ để ghép với người hướng ngoại còn thiếu không
            //3 là số người tối đa trong 1 lều, r là số người hướng ngoại bị dư -> 3 - r là số người linh hoạt tối thiểu cần thiết
                extrovert += (3 - r);
                universal -= (3 - r);
                //Tăng số người hướng ngoại lên bao nhiêu là giảm số người linh hoạt đi bất nhiêu 
                res += extrovert / 3;
                if(universal % 3 == 0)
                    res += universal / 3;
                else res += universal / 3 + 1;
                Console.WriteLine(res);
            } else
                Console.WriteLine("-1");
        }
    }
}