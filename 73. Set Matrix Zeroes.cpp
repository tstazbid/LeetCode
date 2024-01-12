// Approach 01
class Solution {
private:
    void setZeros(vector<vector<int>>& matrix, int row, int column, vector<vector<bool>>& change) {
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][column] != 0) change[i][column] = true;
            matrix[i][column] = 0;
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[row][i] != 0) change[row][i] = true;
            matrix[row][i] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> change(rows, vector<bool>(columns));
        
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[0].size(); c++) {
                if(matrix[r][c] == 0 && change[r][c] == false) {
                    setZeros(matrix, r, c, change);
                }
            }
        }
    }
};

// Time Complexity: O(M * N * (M + N))
// Space Complexity: O(M * N)

// Approach 02
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> rows(n, false), columns(m, false);

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == 0) {
                    rows[r] = true;
                    columns[c] = true;
                }
            }
        }
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(rows[r] || columns[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};

// Time Complexity: O(M * N)
// Space Complexity: O(M + N)