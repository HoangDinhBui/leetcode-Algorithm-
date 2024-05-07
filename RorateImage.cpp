#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solution;
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    solution.rotate(matrix);
    
    cout << "\nMatrix after rotation:" << endl;
    printMatrix(matrix);

    return 0;
}
