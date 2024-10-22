public class Solution {
    public string AddBinary(string a, string b) {
        StringBuilder res = new StringBuilder();
        int i = a.Length - 1;
        int j = b.Length - 1;
        int carry = 0;
        while(i >= 0 || j >= 0) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            res.Append(sum % 2);
            carry = sum / 2;
        }
        if(carry > 0) res.Append('1');
        char[] resultArray = res.ToString().ToCharArray();
        Array.Reverse(resultArray);
        return new string(resultArray);
    }
}