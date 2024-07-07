class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dpX(row, vector<int>(col, 0)), dpY(row, vector<int>(col, 0));
        int subMatrix = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i == 0 && j == 0) {
                    dpX[i][j] = grid[i][j] == 'X' ? 1 : 0;
                    dpY[i][j] = grid[i][j] == 'Y' ? 1 : 0;
                }
                else if(i == 0) {
                    dpX[i][j] = dpX[i][j - 1] + (grid[i][j] == 'X' ? 1 : 0);
                    dpY[i][j] = dpY[i][j - 1] + (grid[i][j] == 'Y' ? 1 : 0);
                } else if(j == 0) {
                    dpX[i][j] = dpX[i - 1][j] + (grid[i][j] == 'X' ? 1 : 0);
                    dpY[i][j] = dpY[i - 1][j] + (grid[i][j] == 'Y' ? 1 : 0);
                } else {
                    dpX[i][j] = (dpX[i - 1][j] + dpX[i][j - 1] + (grid[i][j] == 'X' ? 1 : 0)) - dpX[i - 1][j - 1];
                    dpY[i][j] = (dpY[i - 1][j] + dpY[i][j - 1] + (grid[i][j] == 'Y' ? 1 : 0)) - dpY[i - 1][j - 1];
                }
                
                if(dpX[i][j] == dpY[i][j] && dpX[i][j] != 0) subMatrix++;
            }
        }
        
        return subMatrix;
    }
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)