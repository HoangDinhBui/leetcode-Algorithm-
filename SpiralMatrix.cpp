#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowCount = matrix.size();
        if (rowCount == 0) return ans; 
        int colCount = matrix[0].size();
        int startRow = 0, startCol = 0, endRow = rowCount - 1, endCol = colCount - 1;
        while (startRow <= endRow && startCol <= endCol) {
            for (int i = startCol; i <= endCol; i++) {
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            for (int i = startRow; i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            if(startRow <= endRow) {
                for (int i = endCol; i >= startCol; i--) {
                    ans.push_back(matrix[endRow][i]); 
                }
                endRow--;
            }
            if(startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}