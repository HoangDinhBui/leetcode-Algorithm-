public class Solution11 {
    public IList<IList<int>> Generate(int numRows) {
        List<IList<int>> pascal = new List<IList<int>>();
        for(int i = 0; i < numRows; i++) {
            List<int> rows = new List<int>(new int[i+1]);
            pascal.Add(rows);
            rows[0] = 1;
            rows[i] = 1;
            for(int j = 1; j < i; j++) {
                rows[j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
}