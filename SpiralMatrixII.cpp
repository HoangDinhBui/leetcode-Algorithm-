#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int count = n * n;
        int startRow = 0, startCol = 0, endRow = n - 1, endCol = n - 1;
        int res = 1;
        while (res <= count) {
            for (int i = startCol; i <= endCol && res <= count; i++) {
                ans[startRow][i] = res;
                res++;
            }
            startRow++;
            for (int i = startRow; i <= endRow && res <= count; i++) {
                ans[i][endCol] = res;
                res++;
            }
            endCol--;
            for (int i = endCol; i >= startCol && res <= count; i--) {
                ans[endRow][i] = res;
                res++;
            }
            endRow--;
            for (int i = endRow; i >= startRow && res <= count; i--) {
                ans[i][startCol] = res;
                res++;
            }
            startCol++;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    Solution solution;
    vector<vector<int>> result = solution.generateMatrix(n);

    cout << "The generated matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
