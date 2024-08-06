/*
    The board is made up of an m x n grid of cells, 
    where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
    Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
    using the following four rules (taken from the above Wikipedia article):
    
    **Rules**
    - Any live cell with fewer than two live neighbors dies as if caused by under-population.
    - Any live cell with two or three live neighbors lives on to the next generation.
    - Any live cell with more than three live neighbors dies, as if by over-population.
    - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

    The next state is created by applying the above rules simultaneously to every cell 
    in the current state, where births and deaths occur simultaneously. 
    Given the current state of the m x n grid board, return the next state.

    Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

*/

class Solution {
public:
    vector<vector<int>>directions{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int checkStatus(vector<vector<int>>& board, int row, int col, int i, int j){
        int cntLive = 0;
        for(auto& dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i < 0 || new_i >= row || new_j < 0 || new_j >= col){
                continue;
            }
            if(board[new_i][new_j]==2 || board[new_i][new_j]==1){
                cntLive++;
            }
        }

        if(board[i][j]==0){
            if(cntLive == 3) return 3;
            else return 0;
        }else{
            if(cntLive<2 || cntLive>3) return 2;
            else return 1;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j] = checkStatus(board, row, col, i, j);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }
    }
};