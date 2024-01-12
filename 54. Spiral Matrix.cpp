/*
Algorithm:
-> Initialize the top, right, bottom, and left boundaries as up, right, down, and left.
-> Initialize the output array spiralOrder.
-> Traverse the elements in spiral order and add each element to spiralOrder:
    -> Traverse from left boundary to right boundary.
    -> Traverse from up boundary to down boundary.
    -> Before we traverse from right to left, we need to make sure that we are not on a row that has already been traversed. If we are not, then we can traverse from right to left.
    -> Similarly, before we traverse from top to bottom, we need to make sure that we are not on a column that has already been traversed. Then we can traverse from down to up.
    -> Remember to move the boundaries by updating left, right, up, and down accordingly.
-> Return result.


Time Complexity: O(M * N)
Space Complexity: O(M * N)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralOrder;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int up = 0, right = columns - 1, down = rows - 1, left = 0;

        while(spiralOrder.size() < rows * columns) {
            // left to right
            for(int col = left; col <= right; col++) {
                spiralOrder.push_back(matrix[up][col]);
            }
            // up to down
            for(int row = up + 1; row <= down; row++) {
                spiralOrder.push_back(matrix[row][right]);
            }
            // confirm that now we are in diffrent row
            if(up != down) {
                // right to left
                for(int col = right - 1; col >= left; col--) {
                    spiralOrder.push_back(matrix[down][col]);
                }
            }

            // confirm that now we are in diffrent column
            if(left != right) {
                // down to up
                for(int row = down - 1; row > up; row--) {
                    spiralOrder.push_back(matrix[row][left]);
                }
            }
            up++;
            right--;
            down--;
            left++;
        }
        return spiralOrder;
    }
};