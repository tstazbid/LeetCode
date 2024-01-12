// Approach 01
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int up = 0, right = n - 1, down = n - 1, left = 0;

        vector<int> temp(n, 0);
        while(up < down && left < right) {
            // temp to up
            for(int col = left; col <= right; col++){
                temp[col] = matrix[up][col];
            }

            // up to right
            for(int row = up; row <= down; row++) {
                swap(temp[row], matrix[row][right]);
            }

            // right to down
            for(int col = right - 1; col >= left; col--) {
                swap(temp[n - col - 1], matrix[down][col]);
            }

            // down to left
            for(int row = down - 1; row >= up; row--) {
                swap(temp[n - row - 1], matrix[row][left]);
            }

            // left to up
            for(int col = left + 1; col < right; col++) {
                swap(temp[col], matrix[up][col]);
            }

            up++;
            down--;
            left++;
            right--;
        }
    }
};

// Time Complexity: O(N * N)
// Space Complexity: O(N)


// Approach 02(optimized)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n; row++) {
            for(int col = row + 1; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        for(int row = 0; row < n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};

// Time Complexity: O(N * N)
// Space Complexity: O(1)