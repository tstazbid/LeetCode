class Solution {
private:
    int calculateNeighbors(vector<vector<int>>& board, int row, int col) {
        vector<int> eightNeighbor = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
        int countLive = 0;
        for(int i = 0; i < 8; i++) {
            int x = row + eightNeighbor[i];
            int y = col + eightNeighbor[i + 1];

            if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
            countLive += board[x][y];
        }

        return countLive;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> neighboringBoard(rows, vector<int>(columns));

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < columns; col++) {
                neighboringBoard[row][col] = calculateNeighbors(board, row, col);
            }
        }

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < columns; col++) {
                if(board[row][col] == 0) {
                    board[row][col] = neighboringBoard[row][col] == 3 ? 1 : 0;
                }
                else {
                    board[row][col] = (neighboringBoard[row][col] == 2 || neighboringBoard[row][col] == 3) ? 1 : 0;
                }
            }
        }
    }
};

// Time Complexity: O(N * M)
// Space Complexity: O(N * M)